#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 998244353
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
template<class T_val, class T_inc> struct binary_indexed_tree {
private: vector<T_val> bit;
public:
    int N;
    void resize(int n) {N = n;}
    binary_indexed_tree(int cap) {
        N = cap;
        bit = vector<T_val>(cap+1);
    }
    void bld() {
        for(int pow = 2,gap = 1; pow <= N; pow <<= 1,gap <<= 1)
            for(int i = pow; i <= N; i += pow) bit[i] += bit[i-gap];
    }
    void build(T_inc *arr_start, T_inc *arr_end) {
        copy(arr_start, arr_end, bit.begin()+1);
        bld();
    }
    void build(istream &in = cin) {
        for(int i = 1; i <= N; i++) in >> bit[i];
        bld();
    }
    void reset(int n = -1) {
        if(n != -1) N = n;
        fill(bit.begin()+1, bit.begin()+N+1, 0);
    }
    void add(int i, T_inc inc) {
        for(; i <= N; i += i&-i) bit[i] = (bit[i]+inc)%MOD;
    }
    T_val qry(int r) {
        T_val ans = 0;
        for(; r; r ^= r&-r) ans = (ans+bit[r])%MOD;
        return ans;
    } T_val query(int l, int r) {return (qry(r)-qry(l-1)+MOD)%MOD;}
    void print(ostream &out = cout) {
        for(int i = 1; i <= N; i++) {out << bit[i] << " ";} out << "\n";
    }
};
binary_indexed_tree<ll, ll> bit1(1000000);
int arr[1000001];
ll pref[1000001];
ll suff[1000001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T; cin >> T;
    for(int t = 1; t <= T; t++) {
        int N; cin >> N;
        bit1.reset(N);
        for(int i = 1; i <= N; i++) {
            cin >> arr[i];
            pref[i] = (bit1.qry(arr[i]-1)+1)%MOD;
            bit1.add(arr[i], pref[i]);
        }
        bit1.reset();
        for(int i = N; i >= 1; i--) {
            suff[i] = (bit1.qry(arr[i]-1)+1)%MOD;
            bit1.add(arr[i], suff[i]);
        }
        //for(int i = 1; i <= N; i++) {cout << pref[i] << " ";} cout << "\n";
        //for(int i = 1; i <= N; i++) {cout << suff[i] << " ";} cout << "\n";
        ll ans = 0;
        for(int i = 1; i <= N; i++) ans = (ans+(ll)pref[i]*suff[i])%MOD;
        cout << ans << "\n";
    }
    return 0;
}