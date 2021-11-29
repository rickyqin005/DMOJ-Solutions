#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T_val, class T_inc, class T_qry> struct binary_indexed_tree {
    int N = 0;
    vector<T_val> bit;
    binary_indexed_tree(int n) {
        N = n; bit = vector<T_val>(n+1,0);}
    binary_indexed_tree(auto *arr, int n) {
        N = n; bit = vector<T_val>(arr, arr+n+1);
        bit[0] = 0;
        for(int pow = 2,gap = 1; pow <= N; pow <<= 1,gap <<= 1) {
            for(int i = pow; i <= N; i += pow) bit[i] += bit[i-gap];
        }}
    void set_range(int n) {N = n;}
    void build(auto *arr) {
        copy(arr+1, arr+N+1, bit.begin()+1);
        for(int pow = 2,gap = 1; pow <= N; pow <<= 1,gap <<= 1) {
            for(int i = pow; i <= N; i += pow) bit[i] += bit[i-gap];
        }}
    void update(int i, T_inc inc) {
        for(; i <= N; i += i&-i) bit[i] += inc;}
    T_qry qry(int i) {
        T_qry ans = 0;
        for(; i; i ^= i&-i) ans += bit[i];
        return ans;
    } T_qry query(int l, int r) {return qry(r)-qry(l-1);}
};
binary_indexed_tree<ll, int, ll> bit1(100000);
binary_indexed_tree<int, int, int> bit2(100000);
int arr[100001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,M; cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i]; bit2.update(arr[i], 1);
    }
    bit1.build(arr);
    char t;
    for(int i = 1,x,v,l,r; i <= M; i++) {
        cin >> t;
        if(t == 'C') {
            cin >> x >> v;
            bit1.update(x, v-arr[x]);
            bit2.update(arr[x], -1);
            bit2.update(v, 1);
            arr[x] = v;
        } else if(t == 'S') {
            cin >> l >> r;
            cout << bit1.query(l,r) << "\n";
        } else {
            cin >> v;
            cout << bit2.qry(v) << "\n";
        }
    }
    return 0;
}