#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> struct segment_tree {
    const T INF = ((T)1<<(8*sizeof(T)-1))-1;
    int N = 0,minp = 0,L,R;
    vector<T> st;
    void set_range(int n) {
        N = n; minp = (1 << (31-__builtin_clz((N-1) << 1)));
    }
    segment_tree(int n) {
        set_range(n);
        st = vector<T>(2*minp,0);
    }
    void build() {
        fill(st.begin()+minp+N, st.end(), INF);
        for(int i = minp-1; i; i--) st[i] = min(st[2*i], st[2*i+1]);
    }
    void build(T *arr) {
        copy(arr+1, arr+N+1, st+minp);
        build();
    }
    void build(istream &in) {
        for(int i = minp; i < minp+N; i++) in >> st[i];
        build();
    }
    void update(int i, T val) {
        i += minp-1;
        st[i] = val;
        for(i >>= 1; i; i >>= 1) st[i] = min(st[2*i], st[2*i+1]);
    }
    T qry(int idx, int s, int e) {
        if(s >= L && e <= R) return st[idx];
        int mid = (s+e)/2;
        return min((mid >= L)?qry(idx*2,s,mid):INF, (mid+1 <= R)?qry(idx*2+1,mid+1,e):INF);
    } T query(int l, int r) {
        L = l; R = r;
        return qry(1,1,minp);
    }
    void print(ostream &out) {
        for(int i = 1; i < minp+N; i++) {out << st[i] << " ";} cout << "\n";
    }
};
segment_tree<int> seg(1<<18);
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,M; cin >> N >> M;
    seg.set_range(N);
    seg.build(cin);
    char c; int l,r,x;
    for(int i = 1; i <= M; i++) {
        cin >> c;
        if(c == 'Q') {
            cin >> l >> r; l++; r++;
            cout << seg.query(l,r) << "\n";
        } else if(c == 'M') {
            cin >> l >> x; l++;
            seg.update(l, x);
        }
    }
    return 0;
}