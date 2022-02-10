#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef pair<int, pii> pipii;
int a[1000002];
bool freq[1000002];
pii range[1000002];
bool comp(pii a, pii b) {return a.s < b.s;}
int st[(1<<21)+1];
void buildST(int N, int stl, int minp) {
    for(int i = minp-1; i > 0; i--) {st[i] = max(st[2*i],st[2*i+1]);}
}
int query(int idx, int s, int e, int l, int r) {
    if(e < l || r < s) return 0;
    if(s >= l && e <= r) return st[idx];
    int mid = (s+e)/2;
    return max((mid >= l)?query(idx*2,s,mid,l,r):0,(mid <= r)?query(idx*2+1,mid+1,e,l,r):0);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(freq, 0, sizeof(freq));
    memset(st, 0, sizeof(st));
    int N,Q; cin >> N >> Q;
    for(int i = 1; i <= N; i++) cin >> a[i];

    int minp = 1<<((int)(log(N-1)/log(2))+1), stl = 2*minp-1;
    //cout << minp << " " << stl << "\n";
    for(int i = 1,pos = 1; i <= N; i++) {
        while(pos <= N) {
            if(freq[a[pos]]) break;
            freq[a[pos]] = 1; pos++;
        }
        freq[a[i]] = 0;
        st[minp+i-1] = (pos-1)-i+1;
        range[i] = mp(i,pos-1);
        //cout << i << " " << pos-1 << "\n";
    }
    buildST(N,stl,minp);
    int lastAns = 0;
    for(int i = 1,l,r,ans; i <= Q; i++) {
        cin >> l >> r;
        l = l^lastAns; r = r^lastAns;
        //cout << l << "  " << r << "\n";
        int lb = lower_bound(range+1, range+N+1, mp(0,r), comp)-range;
        //cout << lb << "\n";
        if(lb <= l) ans = query(1,1,minp,lb,l);
        else ans = 0;
        cout << ans << "\n";
        lastAns = ans;
    }
    //for(int i = 1; i <= stl; i++) {cout << st[i] << " ";} cout << "\n";
    return 0;
}