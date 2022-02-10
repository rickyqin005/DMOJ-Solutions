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
        int height = 0, bf = 0;
        int cntSub = 1;
        Node(T_key v){key = v;}
    };
    Node *_root = nullptr;
    bool _treeChange;//for insert and erase operations
    T_key _newNodeKey;//for erase operations (special case)
    int _newNodeFreq;//for erase operations (special case)
    void _update(Node *curr) {//updates height and count
        int lh = (curr->left==nullptr?0:curr->left->height+1);
        int rh = (curr->right==nullptr?0:curr->right->height+1);
        curr->height = max(lh, rh);
        curr->bf = rh-lh;
        curr->cntSub = (curr->left==nullptr?0:curr->left->cntSub)+(curr->right==nullptr?0:curr->right->cntSub)+curr->freq;
    }
    void _update_count(Node *curr) {//updates count only
        curr->cntSub = (curr->left==nullptr?0:curr->left->cntSub)+(curr->right==nullptr?0:curr->right->cntSub)+curr->freq;
    }
    Node* _balance(Node *curr) {//rotates the subtree, if necessary
        if(curr->bf == -2) {
            if(curr->left->bf <= 0) { //left left
                Node *lchild = curr->left;
                curr->left = lchild->right;
                lchild->right = curr;
                curr = lchild;
                _update(curr->right);
            } else { //left right
                Node *lrchild = curr->left->right;
                curr->left->right = lrchild->left;
                lrchild->left = curr->left;
                curr->left = lrchild->right;
                lrchild->right = curr;
                curr = lrchild;
                _update(curr->left);
                _update(curr->right);
            }
            _update(curr);
        } else if(curr->bf == 2) {
            if(curr->right->bf >= 0) { //right right
                Node *rchild = curr->right;
                curr->right = rchild->left;
                rchild->left = curr;
                curr = rchild;
                _update(curr->left);
            } else { //right left
                Node *rlchild = curr->right->left;
                curr->right->left = rlchild->right;
                rlchild->right = curr->right;
                curr->right = rlchild->left;
                rlchild->left = curr;
                curr = rlchild;
                _update(curr->right);
                _update(curr->left);
            }
            _update(curr);
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
        if(_treeChange) {//only rebalance if node is deleted
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
                } else {
                    if(curr->right == nullptr) {//one left child
                        Node* lchild = curr->left;
                        delete curr;
                        return lchild;
                    } else {//two children
                        curr->left = _erase_special(curr->left);
                        curr->key = _newNodeKey;//largest key less than the current key
                        curr->freq = _newNodeFreq;
                    }
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
        if(curr == nullptr) return -1;//index out of bounds
        int cmp = minIdx+(curr->left==nullptr?0:curr->left->cntSub);
        if(targetIdx < cmp) return _kth_smallest(curr->left, minIdx, targetIdx);
        else if(targetIdx < cmp+curr->freq) return curr->key;//found index
        else return _kth_smallest(curr->right, cmp+curr->freq, targetIdx);
    }
    T_key _kth_largest(const Node *curr, const int minIdx, const int targetIdx) {
        if(curr == nullptr) return -1;//index out of bounds
        int cmp = minIdx+(curr->right==nullptr?0:curr->right->cntSub);
        if(targetIdx < cmp) return _kth_largest(curr->right, minIdx, targetIdx);
        else if(targetIdx < cmp+curr->freq) return curr->key;//found index
        else return _kth_largest(curr->left, cmp+curr->freq, targetIdx);
    }
    int _rank_inc_of(const Node *curr, const int currIdx, const T_key key) {
        if(curr == nullptr) return -1;//not found
        if(key == curr->key) return currIdx+(curr->left==nullptr?0:curr->left->cntSub);//found key
        else if(key < curr->key) return _rank_inc_of(curr->left, currIdx, key);
        else return _rank_inc_of(curr->right, currIdx+(curr->left==nullptr?0:curr->left->cntSub)+curr->freq, key);
    }
    int _rank_dec_of(const Node *curr, const int currIdx, const T_key key) {
        if(curr == nullptr) return -1;//not found
        if(key == curr->key) return currIdx+(curr->right==nullptr?0:curr->right->cntSub);//found key
        else if(key < curr->key) return _rank_dec_of(curr->left, currIdx+(curr->right==nullptr?0:curr->right->cntSub)+curr->freq, key);
        else return _rank_dec_of(curr->right, currIdx, key);
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
        _root = _insert(_root, key);
        return _treeChange;
    }
    bool erase(const T_key key) {
        _treeChange = false;
        _root = _erase(_root, key);
        return _treeChange;
    }
    T_key kth_smallest(const int idx) {
        return _kth_smallest(_root, 1, idx);
    }
    T_key kth_largest(const int idx) {
        return _kth_largest(_root, 1, idx);
    }
    int rank_inc_of(const T_key key) {
        return _rank_inc_of(_root, 1, key);
    }
    int rank_dec_of(const T_key key) {
        return _rank_dec_of(_root, 1, key);
    }
};
order_statistic_tree<int> bbst;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T; cin >> T;
    ll sum = 0;
    for(int i = 1,x; i <= T; i++) {
        cin >> x;
        bbst.insert(x);
        sum += bbst.rank_dec_of(x);
    }
    printf("%.02f\n", (double)sum/T);
    return 0;
}