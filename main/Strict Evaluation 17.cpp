#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> struct range_segment_tree {
private:
    const T INF = 0x7f7f7f7f7f7f7f7f;
    int minp = 0,L,R,V;
    vector<T> st, lzy1, lzy2;
public:
    int N;
    void set_range(int n) {
        N = n; minp = (1 << (31-__builtin_clz((N-1) << 1)));
    }
    range_segment_tree(int n) {
        set_range(n);
        st = vector<T>(2*minp);
        lzy1 = vector<T>(2*minp);
        lzy2 = vector<T>(2*minp);
    }
    void bld() {
        fill(st.begin()+minp+N, st.end(), INF);
        for(int i = minp-1; i; i--) st[i] = min(st[2*i], st[2*i+1]);
    }
    void build(T *arr_start, T *arr_end) {
        copy(arr_start, arr_end, st.begin()+minp);
        bld();
    }
    void build(istream &in = cin) {
        for(int i = minp; i < minp+N; i++) in >> st[i];
        bld();
    }
    void reset() {
        fill(st.begin()+minp, st.end(), 0);
        fill(lzy1.begin(), lzy1.end(), 0);
        fill(lzy2.begin(), lzy2.end(), 0);
    }
    inline void propagate(int idx) {
        if(lzy2[idx] != 0) {
            st[idx*2] = st[idx*2+1] = lzy2[idx];
            lzy2[idx*2] = lzy2[idx*2+1] = lzy2[idx];
            lzy1[idx*2] = lzy1[idx*2+1] = lzy2[idx] = 0;
        }
        if(lzy1[idx] != 0) {
            st[idx*2] += lzy1[idx];
            st[idx*2+1] += lzy1[idx];
            lzy1[idx*2] += lzy1[idx];
            lzy1[idx*2+1] += lzy1[idx];
            lzy1[idx] = 0;
        }
    }
    void increment_recurse(int idx, int s, int e) {
        if(L <= s && e <= R) {
            st[idx] += V;
            lzy1[idx] += V;
            return;
        }
        propagate(idx);
        int mid = (s+e)/2;
        if(mid >= L) increment_recurse(idx*2, s, mid);
        if(mid+1 <= R) increment_recurse(idx*2+1, mid+1, e);
        st[idx] = min(st[idx*2], st[idx*2+1]);
    } void increment(int l, int r, int val) {
        L = l; R = r; V = val;
        increment_recurse(1,1,minp);
    }
    void set_recurse(int idx, int s, int e) {
        if(L <= s && e <= R) {
            st[idx] = V;
            lzy1[idx] = 0;
            lzy2[idx] = V;
            return;
        }
        propagate(idx);
        int mid = (s+e)/2;
        if(mid >= L) set_recurse(idx*2, s, mid);
        if(mid+1 <= R) set_recurse(idx*2+1, mid+1, e);
        st[idx] = min(st[idx*2], st[idx*2+1]);
    } void set(int l, int r, int val) {
        L = l; R = r; V = val;
        set_recurse(1,1,minp);
    }
    T query_recurse(int idx, int s, int e) {
        if(L <= s && e <= R) return st[idx];
        propagate(idx);
        int mid = (s+e)/2;
        return min((mid >= L)?query_recurse(idx*2, s, mid):INF, (mid+1 <= R)?query_recurse(idx*2+1, mid+1, e):INF);
    } T query(int l, int r) {
        L = l; R = r;
        return query_recurse(1,1,minp);
    }
    void print(ostream &out = cout) {
        for(int i = 1; i < minp+N; i++) {out << st[i] << " ";} out << "\n";
        for(int i = 1; i < minp+N; i++) {out << lzy1[i] << " ";} out << "\n";
        for(int i = 1; i < minp+N; i++) {out << lzy2[i] << " ";} out << "\n";
    }
};
range_segment_tree<ll> seg(100000);
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,Q; cin >> N >> Q;
    seg.set_range(N);
    seg.build();
    for(int i = 1,c,l,r,v; i <= Q; i++) {
        cin >> c >> l >> r;
        if(c == 1) {
            cin >> v; seg.increment(l,r,v);
        } else if(c == 2) {
            cin >> v; seg.set(l,r,v);
        } else cout << seg.query(l,r) << "\n";
    }
    return 0;
}