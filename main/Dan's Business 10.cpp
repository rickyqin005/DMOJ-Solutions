#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807
#define MAX_DOUBLE 1e18
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef vector<int> vii;
typedef vector<ll> vll;
int N,M,minPow,stLen;
bool flag = false;
int st[(1<<21)+1];
int lzy[(1<<21)+1];
void buildST() {
    minPow = N-1; int cnt = 0;
    for(;minPow != 0; minPow >>= 1, cnt++);
    minPow = 1<<cnt;
    stLen = minPow*2-1;
    for(int i = minPow; i < minPow+N; i++) {cin >> st[i];}
    for(int i = minPow-1; i > 0; i--) {st[i] = min(st[2*i], st[2*i+1]);}
}
void propagate(int idx, int s, int e) {
    if(lzy[idx] != 0 && s != e) {
        lzy[idx*2] += lzy[idx];
        st[idx*2] += lzy[idx];
        lzy[idx*2+1] += lzy[idx];
        st[idx*2+1] += lzy[idx];
        if(st[idx*2] < 0 || st[idx*2+1] < 0) flag = true;
        lzy[idx] = 0;
    }
}
void update(int idx, int s, int e, int l, int r, int val) {
    if(e < l || s > r) return;
    propagate(idx,s,e);
    if(s >= l && e <= r) {
        st[idx] += val;
        lzy[idx] += val;
        if(st[idx] < 0) flag = true;
        return;
    }
    int mid = (s+e)/2;
    if(mid >= l) update(idx*2, s, mid, l, r, val);
    if(mid <= r) update(idx*2+1, mid+1, e, l, r, val);
    st[idx] = min(st[idx*2], st[idx*2+1]);
    if(st[idx] < 0) flag = true;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(st, 0x7f, sizeof(st));
    cin >> N >> M;
    buildST();
    for(int i = 1,v,s,t; i <= M; i++) {
        cin >> v >> s >> t;
        update(1,1,minPow,s,t,-v);
        if(flag) {
            cout << -1 << "\n" << i << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
    return 0;
}