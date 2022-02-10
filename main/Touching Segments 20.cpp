#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;
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
    void build() {
        fill(st.begin()+minp+N, st.end(), -INF);
        for(int i = minp-1; i; i--) st[i] = max(st[2*i], st[2*i+1]);
    }
    void build(T *arr_start, T *arr_end) {
        copy(arr_start, arr_end, st.begin()+minp);
        build();
    }
    void build(istream &in) {
        for(int i = minp; i < minp+N; i++) in >> st[i];
        build();
    }
    void reset() {
        fill(st.begin(), st.end(), -INF);
        fill(lzy1.begin(), lzy1.end(), 0);
        fill(lzy2.begin(), lzy2.end(), 0);
    }
    void propagate(int idx) {
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
        st[idx] = max(st[idx*2], st[idx*2+1]);
    } void increment(int l, int r, int val) {
        L = l; R = r; V = val;
        increment_recurse(1,1,minp);
    }
    void set_value_recurse(int idx, int s, int e) {
        if(L <= s && e <= R) {
            st[idx] = V;
            lzy1[idx] = 0;
            lzy2[idx] = V;
            return;
        }
        propagate(idx);
        int mid = (s+e)/2;
        if(mid >= L) set_value_recurse(idx*2, s, mid);
        if(mid+1 <= R) set_value_recurse(idx*2+1, mid+1, e);
        st[idx] = max(st[idx*2], st[idx*2+1]);
    } void set_value(int l, int r, int val) {
        L = l; R = r; V = val;
        set_value_recurse(1,1,minp);
    }
    T query_recurse(int idx, int s, int e) {
        if(L <= s && e <= R) return st[idx];
        propagate(idx);
        int mid = (s+e)/2;
        return max((mid >= L)?query_recurse(idx*2, s, mid):-INF, (mid+1 <= R)?query_recurse(idx*2+1, mid+1, e):-INF);
    } T query(int l, int r) {
        L = l; R = r;
        return query_recurse(1,1,minp);
    }
    void print(ostream &out) {
        for(int i = 1; i < minp+N; i++) {out << st[i] << " ";} cout << "\n";
        for(int i = 1; i < minp+N; i++) {out << lzy1[i] << " ";} cout << "\n";
        for(int i = 1; i < minp+N; i++) {out << lzy2[i] << " ";} cout << "\n";
    }
};
range_segment_tree<int> seg(200000);
vector<int> point;
pii line[100001];
pii rng[200002];
int diff[200002];
bool comp(pii a, pii b) {return a.f < b.f;}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T; cin >> T;
    for(int t = 1; t <= T; t++) {
        memset(line, 0, sizeof(line));
        memset(rng, 0, sizeof(rng));
        memset(diff, 0, sizeof(diff));
        int N,P; cin >> N;
        for(int i = 1; i <= N; i++) {
            cin >> line[i].f >> line[i].s;
            point.pb(line[i].f);
            point.pb(line[i].s);
        }
        sort(point.begin(), point.end());
        point.erase(unique(point.begin(), point.end()), point.end());
        P = point.size();
        //for(int i = 1; i <= P; i++) cout << point[i] << endl;
        for(int i = 1; i <= N; i++) {
            line[i].f = lower_bound(point.begin(), point.end(), line[i].f)-point.begin()+1;
            line[i].s = lower_bound(point.begin(), point.end(), line[i].s)-point.begin()+1;
            diff[line[i].f]++;
            diff[line[i].s+1]--;
            rng[2*i-1] = line[i];
            rng[2*i] = mp(line[i].s+1, line[i].f);
        }
        for(int i = 1; i <= P; i++) diff[i] += diff[i-1];
        sort(rng+1, rng+2*N+1, comp);
        seg.set_range(P);
        seg.build(diff+1, diff+P+1);
        int ans = 0,currLine = 0;
        for(int i = 1; i <= 2*N; i++) {
            if(rng[i].f > 1000000000) break;
            if(rng[i].f > rng[i].s) {
                seg.increment(rng[i].s, rng[i].f-1, 1);
                currLine--;
            } else {
                seg.increment(rng[i].f, rng[i].s, -1);
                currLine++;
            }
            if(rng[i+1].f != rng[i].f) ans = max(ans, currLine+seg.query(1,P));
        }
        cout << "Case " << t << ": " << ans << "\n";
        seg.reset();
        point.clear();
    }
    return 0;
}