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
template<class T_val, class T_inc> struct binary_indexed_tree {
private: vector<T_val> bit;
public:
    int N;
    void resize(int n) {N = n;}
    binary_indexed_tree(int cap) {
        resize(cap);
        bit = vector<T_val>(cap+1,0);
    }
    void bld() {
        for(int pow = 2,gap = 1; pow <= N; pow <<= 1,gap <<= 1) {
            for(int i = pow; i <= N; i += pow) bit[i] += bit[i-gap];
        }
    }
    void build(T_inc *arr_start, T_inc *arr_end) {
        copy(arr_start, arr_end, bit.begin()+1);
        bld();
    }
    void build(istream &in = cin) {
        for(int i = 1; i <= N; i++) in >> bit[i];
        bld();
    }
    void clear() {
        fill(bit.begin()+1, bit.begin()+N+1, 0);
    }
    void add(int i, T_inc inc) {
        for(; i <= N; i += i&-i) bit[i] += inc;
    }
    T_val qry(int i) {
        T_val ans = 0;
        for(; i; i ^= i&-i) ans += bit[i];
        return ans;
    } T_val query(int l, int r) {return qry(r)-qry(l-1);}
    void print(ostream &out = cout) {
        for(int i = 1; i <= N; i++) {out << bit[i] << " ";} out << "\n";
    }
};
binary_indexed_tree<ll, ll> odd(1000000);
binary_indexed_tree<ll, ll> even(1000000);
int arr[1000001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N,Q; cin >> N >> Q;
    odd.resize(N);
    even.resize(N);
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        if(i%2 == 1) odd.add(i, arr[i]);
        else even.add(i, arr[i]);
    }
    for(int i = 1,t,a,b; i <= Q; i++) {
        cin >> t >> a >> b;
        if(t == 1) {
            if(a%2 == 1) odd.add(a, b-arr[a]);
            else even.add(a, b-arr[a]);
            arr[a] = b;
        } else if(t == 2) {
            if(a%2 == 1) cout << odd.query(a,b) << "\n";
            else cout << even.query(a,b) << "\n";
        }
    }
    return 0;
}