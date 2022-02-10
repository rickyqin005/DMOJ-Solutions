#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
#define MAXST (1<<21)
int stlen,minpow;
int st[MAXST+1];
bool lzy[MAXST+1];
void propagate(int idx, int s, int e) {
    if(lzy[idx] && s != e) {
        lzy[idx*2] = !lzy[idx*2];
        st[idx*2] = (e-s+1)/2-st[idx*2];
        lzy[idx*2+1] = !lzy[idx*2+1];
        st[idx*2+1] = (e-s+1)/2-st[idx*2+1];
        lzy[idx] = false;
    }
}
int query(int idx, int s, int e, int n) {
    propagate(idx,s,e);
    if(s == e) return s;
    int mid = (s+e)/2;
    if(n <= st[idx*2]) return query(idx*2, s, mid, n);
    else return query(idx*2+1, mid+1, e, n-st[idx*2]);
}
void update(int idx, int s, int e, int l, int r) {
    if(e < l || s > r) return;
    propagate(idx,s,e);
    if(s >= l && e <= r) {
        st[idx] = (e-s+1)-st[idx];
        lzy[idx] = !lzy[idx];
        return;
    }
    int mid = (s+e)/2;
    if(mid >= l) update(idx*2, s, mid, l, r);
    if(mid <= r) update(idx*2+1, mid+1, e, l, r);
    st[idx] = st[idx*2]+st[idx*2+1];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(st, 0, sizeof(st));
    memset(lzy, 0, sizeof(lzy));
    int N,M,L; cin >> N >> M >> L;
    minpow = N-1; int cnt = 0;
    for(;minpow != 0; minpow >>= 1, cnt++);
    minpow = 1<<cnt;
    stlen = minpow*2-1;
    for(int i = minpow; i < minpow+N; i++) {st[i] = 1;}
    for(int i = minpow-1; i > 0; i--) {st[i] = st[i*2]+st[i*2+1];}
    for(int i = 0,a,b; i < M; i++) {
        cin >> a >> b;
        update(1,1,minpow,a,b);
        if(st[1] < L) cout << "AC?" << "\n";
        else cout << query(1,1,minpow,L) << "\n";
    }
    return 0;
}