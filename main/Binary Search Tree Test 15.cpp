#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
template<class T_key> struct order_statistic_tree {
private:
    struct Node {
        T_key key = 0, freq = 1;
        Node *left = nullptr, *right = nullptr;
        int height = 0, cntSub = 1;
        Node(T_key v){key = v;}
    };
    Node *_root = nullptr;
    bool _treeChange;//for insert and erase operations
    T_key _newNodeKey;//for erase operations (special case)
    int _newNodeFreq;//for erase operations (special case)
    int numberOfTreeRotations;
    int _get_bf(const Node *curr) const {
        return (curr==nullptr?0:((curr->right==nullptr?-1:curr->right->height)-(curr->left==nullptr?-1:curr->left->height)));
    }
    void _update(Node *curr) {//updates height and count
        curr->height = max(curr->left==nullptr?-1:curr->left->height, curr->right==nullptr?-1:curr->right->height)+1;
        curr->cntSub = (curr->left==nullptr?0:curr->left->cntSub)+(curr->right==nullptr?0:curr->right->cntSub)+curr->freq;
    }
    void _update_count(Node *curr) {//updates count only
        curr->cntSub = (curr->left==nullptr?0:curr->left->cntSub)+(curr->right==nullptr?0:curr->right->cntSub)+curr->freq;
    }
    Node* _balance(Node *curr) {//rotates the subtree, if necessary
        int currBf = _get_bf(curr);
        if(currBf == -2) {
            if(_get_bf(curr->left) <= 0) { //left left
                Node *lchild = curr->left;
                curr->left = lchild->right;
                lchild->right = curr;
                curr = lchild;
            } else { //left right
                Node *lrchild = curr->left->right;
                curr->left->right = lrchild->left;
                lrchild->left = curr->left;
                curr->left = lrchild->right;
                lrchild->right = curr;
                curr = lrchild;
                _update(curr->left);
            }
            _update(curr->right);
            _update(curr);
            numberOfTreeRotations++;
        } else if(currBf == 2) {
            if(_get_bf(curr->right) >= 0) { //right right
                Node *rchild = curr->right;
                curr->right = rchild->left;
                rchild->left = curr;
                curr = rchild;
            } else { //right left
                Node *rlchild = curr->right->left;
                curr->right->left = rlchild->right;
                rlchild->right = curr->right;
                curr->right = rlchild->left;
                rlchild->left = curr;
                curr = rlchild;
                _update(curr->right);
            }
            _update(curr->left);
            _update(curr);
            numberOfTreeRotations++;
        }
        return curr;
    }
    bool _contains(const Node *curr, const T_key key) const {
        if(curr == nullptr) return false;
        if(key < curr->key) return _contains(curr->left, key);
        else if(key > curr->key) return _contains(curr->right, key);
        return true;
    }
    void _clear(const Node *curr) {
        if(curr->left != nullptr) _clear(curr->left);
        if(curr->right != nullptr) _clear(curr->right);
        delete curr;
    }
    Node* _insert(Node *curr, const T_key key) {
        if(curr == nullptr) {//insert new key
            curr = new Node(key);
            size++;
            sizeUnique++;
            _treeChange = true;
            return curr;
        } else if(key < curr->key) curr->left = _insert(curr->left, key);
        else if(key > curr->key) curr->right = _insert(curr->right, key);
        else {//key already exists
            size++;
            curr->freq++;
            curr->cntSub++;
            return curr;
        }
        if(_treeChange) {//only rebalance if node is added
            _update(curr);
            return _balance(curr);
        } else _update_count(curr);
        return curr;
    }
    Node* _erase_special(Node *curr) {
        if(curr->right == nullptr) {
            _newNodeKey = curr->key;
            _newNodeFreq = curr->freq;
            Node* lchild = curr->left;
            delete curr;
            return lchild;
        }
        curr->right = _erase_special(curr->right);
        _update(curr);
        return _balance(curr);
    }
    Node* _erase(Node *curr, const T_key key) {
        if(curr == nullptr) return nullptr;//key does not exist
        if(key == curr->key) {//found the key
            size--;
            curr->freq--;
            curr->cntSub--;
            if(curr->freq == 0) {//delete node
                _treeChange = true;
                sizeUnique--;
                if(curr->left == nullptr) {//one right child OR no children
                    Node* rchild = curr->right;
                    delete curr;
                    return rchild;
                } else if(curr->right == nullptr) {//one left child
                    Node* lchild = curr->left;
                    delete curr;
                    return lchild;
                } else {//two children
                    curr->left = _erase_special(curr->left);
                    curr->key = _newNodeKey;//largest key less than the current key
                    curr->freq = _newNodeFreq;
                }
            } else return curr;
        } else if(key < curr->key) curr->left = _erase(curr->left, key);
        else curr->right = _erase(curr->right, key);
        if(_treeChange) {//only rebalance if node is deleted
            _update(curr);
            return _balance(curr);
        } else _update_count(curr);
        return curr;
    }
    T_key _kth_smallest(const Node *curr, const int minIdx, const int targetIdx) {
        int cmp = minIdx+(curr->left==nullptr?0:curr->left->cntSub);
        if(targetIdx < cmp) return _kth_smallest(curr->left, minIdx, targetIdx);
        else if(targetIdx < cmp+curr->freq) return curr->key;//found index
        else return _kth_smallest(curr->right, cmp+curr->freq, targetIdx);
    }
    T_key _kth_largest(const Node *curr, const int minIdx, const int targetIdx) {
        int cmp = minIdx+(curr->right==nullptr?0:curr->right->cntSub);
        if(targetIdx < cmp) return _kth_largest(curr->right, minIdx, targetIdx);
        else if(targetIdx < cmp+curr->freq) return curr->key;//found index
        else return _kth_largest(curr->left, cmp+curr->freq, targetIdx);
    }
    int _rank_ascending(const Node *curr, const int currIdx, const T_key key) {
        if(curr == nullptr) return -1;//not found
        if(key == curr->key) return currIdx+(curr->left==nullptr?0:curr->left->cntSub);//found key
        else if(key < curr->key) return _rank_ascending(curr->left, currIdx, key);
        else return _rank_ascending(curr->right, currIdx+(curr->left==nullptr?0:curr->left->cntSub)+curr->freq, key);
    }
    int _rank_descending(const Node *curr, const int currIdx, const T_key key) {
        if(curr == nullptr) return -1;//not found
        if(key == curr->key) return currIdx+(curr->right==nullptr?0:curr->right->cntSub);//found key
        else if(key < curr->key) return _rank_descending(curr->left, currIdx+(curr->right==nullptr?0:curr->right->cntSub)+curr->freq, key);
        else return _rank_descending(curr->right, currIdx, key);
    }
    void _preorder_traverse(const Node *curr) const {
        if(curr == nullptr) return;
        cout << curr->key << " appears " << curr->freq << " time(s), has a height of " << curr->height << ", a bf of " << _get_bf(curr) << " and " << curr->cntSub << " node(s) in its subtree" << endl;
        if(curr->left != nullptr) {
            cout << curr->key << " -> " << curr->left->key << endl;
            _preorder_traverse(curr->left);
        }
        if(curr->right != nullptr) {
            cout << curr->key << " -> " << curr->right->key << endl;
            _preorder_traverse(curr->right);
        }
    }
    void _inorder_traverse(const Node *curr) const {
        if(curr == nullptr) return;
        if(curr->left != nullptr) _inorder_traverse(curr->left);
        for(int i = 1; i <= curr->freq; i++) {cout << curr->key << " ";}
        if(curr->right != nullptr) _inorder_traverse(curr->right);
    }
public:
    int size = 0;
    int sizeUnique = 0;
    bool empty() const {
        return (size == 0);
    }
    bool contains(const T_key key) const {
        return _contains(_root, key);
    }
    void clear() {
        if(_root->left != nullptr) _clear(_root->left);
        if(_root->right != nullptr) _clear(_root->right);
        _root = nullptr;
        size = 0;
        sizeUnique = 0;
    }
    bool insert(const T_key key) {
        _treeChange = false;
        numberOfTreeRotations = 0;
        _root = _insert(_root, key);
        assert(numberOfTreeRotations <= 1);
        return _treeChange;
    }
    bool erase(const T_key key) {
        _treeChange = false;
        _root = _erase(_root, key);
        return _treeChange;
    }
    T_key kth_smallest(const int idx) {
        if(idx > size || idx < 1) return -1;
        return _kth_smallest(_root, 1, idx);
    }
    T_key kth_largest(const int idx) {
        if(idx > size || idx < 1) return -1;
        return (_root==nullptr?-1:_kth_largest(_root, 1, idx));
    }
    int rank_ascending(const T_key key) {
        return _rank_ascending(_root, 1, key);
    }
    int rank_descending(const T_key key) {
        return _rank_descending(_root, 1, key);
    }
    void preorder_traverse() const {
        if(_root != nullptr) _preorder_traverse(_root);
    }
    void inorder_traverse() const {
        if(_root != nullptr) _inorder_traverse(_root);
    }
};
order_statistic_tree<int> bbst;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,M; cin >> N >> M;
    for(int i = 1,v; i <= N; i++) {
        cin >> v;
        bbst.insert(v);
    }
    int lastAns = 0;
    char chr;
    for(int i = 1,v; i <= M; i++) {
        cin >> chr >> v;
        v = v^lastAns;
        if(chr == 'I') {
            bbst.insert(v);
        } else if(chr == 'R') {
            bbst.erase(v);
        } else if(chr == 'S') {
            lastAns = bbst.kth_smallest(v);
            cout << lastAns << "\n";
        } else if(chr == 'L') {
            lastAns = bbst.rank_ascending(v);
            cout << lastAns << "\n";
        }
    }
    bbst.inorder_traverse();
    cout << "\n";
    return 0;
}