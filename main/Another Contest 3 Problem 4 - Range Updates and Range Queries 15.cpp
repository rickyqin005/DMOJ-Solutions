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
#define MAXN 1000000
#define MAXST (1<<21)
int N, Q, stLen, minPow;
ll st[MAXST+1];
ll lzy1[MAXST+1];//first number in series
ll lzy2[MAXST+1];//gap
void buildST() {
    minPow = N-1; int cnt = 0;
    while(minPow != 0) {
        minPow >>= 1;
        cnt++;
    }
    minPow = 1<<cnt;
    stLen = minPow*2-1;
}
void propagate(int idx, int s, int e) {
    if(lzy1[idx] != 0 && s != e) {
        lzy1[idx*2] += lzy1[idx];
        lzy2[idx*2] += lzy2[idx];
        st[idx*2] += (ll)((e-s+1)/2)*(2*lzy1[idx]+lzy2[idx]*((e-s)/2))/2;
        lzy1[idx*2+1] += lzy1[idx]+lzy2[idx]*((e-s+1)/2);
        lzy2[idx*2+1] += lzy2[idx];
        st[idx*2+1] += (ll)((e-s+1)/2)*(2*(lzy1[idx]+lzy2[idx]*((e-s+1)/2))+lzy2[idx]*((e-s)/2))/2;
        lzy1[idx] = 0;
        lzy2[idx] = 0;
    }
}
ll query(int idx, int s, int e, int l, int r) {
    if(e < l || s > r) return 0;
    propagate(idx,s,e);
    if(s >= l && e <= r) return st[idx];
    int mid = (s+e)/2;
    return query(idx*2, s, mid, l, r) + query(idx*2+1, mid+1, e, l, r);
}
void update(int idx, int s, int e, int l, int r, int a) {
    if(e < l || s > r) return;
    propagate(idx,s,e);
    if(s >= l && e <= r) {
        ll first = (ll)a*(s-l+1);
        st[idx] += (ll)(e-s+1)*(2*first+a*(e-s))/2;
        lzy1[idx] += first;
        lzy2[idx] += a;
        return;
    }
    int mid = (s+e)/2;
    update(idx*2, s, mid, l, r, a);
    update(idx*2+1, mid+1, e, l, r, a);
    st[idx] = st[idx*2]+st[idx*2+1];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    memset(st, 0, sizeof(st));
    memset(lzy1, 0, sizeof(lzy1));
    memset(lzy2, 0, sizeof(lzy2));
    cin >> N >> Q;
    buildST();
    int t,l,r,a;
    for(int i = 0; i < Q; i++) {
        cin >> t;
        if(t == 1) {
            cin >> l >> r >> a;
            update(1,1,minPow,l,r,a);
        } else {
            cin >> l >> r;
            cout << query(1,1,minPow,l,r) << "\n";
        }
    }
    /*
    for(int i = 1; i <= stLen; i++) {cout << st[i] << " ";} cout << "\n";
    for(int i = 1; i <= stLen; i++) {cout << lzy1[i] << " ";} cout << "\n";
    for(int i = 1; i <= stLen; i++) {cout << lzy2[i] << " ";} cout << "\n";
    */
    return 0;
}