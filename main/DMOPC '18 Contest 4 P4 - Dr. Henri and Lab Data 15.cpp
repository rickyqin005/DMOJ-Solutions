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
typedef pair<int, double> pid;
typedef pair<double, int> pdi;
typedef pair<pii, pii> ppiipii;
typedef vector<int> vii;
typedef vector<ll> vll;
#define MAXN 200000
int N, Q;
pii arr[MAXN+2];
ll preArr[MAXN+1];
ll bit[MAXN+1];
ll ans[MAXN+1];
ppiipii q[MAXN+1];
bool comp(ppiipii a, ppiipii b) {
    return a.s.f < b.s.f;
}
ll query(int L, int R) {
    ll ans = 0;
    int pow = 1;
    while(R > 0) {
        if((R & pow) == pow) {
            ans += bit[R];
            R ^= pow;
        }
        pow <<= 1;
    }
    L--;
    pow = 1;
    while(L > 0) {
        if((L & pow) == pow) {
            ans -= bit[L];
            L ^= pow;
        }
        pow <<= 1;
    }
    return ans;
}
void update(int idx, int inc) {
    while(idx <= N) {
        bit[idx] += inc;
        idx += idx & -idx;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    memset(bit, 0, sizeof(bit));
    memset(arr, 0, sizeof(arr));
    memset(ans, 0, sizeof(ans));
    memset(preArr, 0, sizeof(preArr));
    memset(q, 0, sizeof(q));
    cin >> N >> Q;
    for(int i = 1,x; i <= N; i++) {
        cin >> x;
        preArr[i] = preArr[i-1]+x;
        arr[i] = mp(x,i);
    }
    for(int i = 1,l,r,k; i <= Q; i++) {
        cin >> l >> r >> k;
        q[i] = mp(mp(l,r),mp(k,i));
    }
    sort(arr+1, arr+N+1);
    sort(q+1, q+Q+1, comp);
    int pos = 1;
    for(int i = 1; i <= Q; i++) {
        while(pos <= N && arr[pos].f < q[i].s.f) {
            //cout << arr[pos].s << " " << arr[pos].f << "\n";
            update(arr[pos].s, arr[pos].f);
            pos++;
        }
        //cout << "ans " << query(q[i].f.f, q[i].f.s) << " " << (preArr[q[i].f.s]-preArr[q[i].f.f-1]) << "\n";
        ans[q[i].s.s] = (preArr[q[i].f.s]-preArr[q[i].f.f-1])-query(q[i].f.f, q[i].f.s)*2;
    }
/*
    cout << "q: \n";for(int i = 1; i <= Q; i++) {cout << q[i].f.f << " " << q[i].f.s << " " << q[i].s.f << " " << q[i].s.s << "\n";} cout << "\n";
    cout << "bit: \n";for(int i = 1; i <= N; i++) {cout << bit[i] << " ";} cout << "\n\n";
    cout << "arr: \n";for(int i = 1; i <= N; i++) {cout << arr[i].f << " " << arr[i].s << "\n";} cout << "\n";
    cout << "preArr: \n";for(int i = 1; i <= N; i++) {cout << preArr[i] << " ";} cout << "\n\n";
*/
    for(int i = 1; i <= Q; i++) {cout << ans[i] << "\n";}
    return 0;
}