#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef pair<int, pii> pipii;
struct Node {int k,p,f;};
Node arr[72];
int dp[72][72][72];
int psa[72];
int N,K;
bool compP(Node a, Node b) {return a.p < b.p;}
bool compK(Node a, Node b) {return a.k < b.k;}
int fun(int l, int r, int w) {
    if(l > r) return 0;
    if(dp[l][r][w] != -1) return dp[l][r][w];
    int ans = INT_MAX, sum = psa[r]-psa[l-1];
    for(int m = l; m <= r; m++) {
        ans = min(ans, fun(l,m-1,w)+fun(m+1,r,w)+sum+K);
        if(arr[m].p >= w) ans = min(ans, fun(l,m-1,arr[m].p)+fun(m+1,r,arr[m].p)+sum);
    }
    return dp[l][r][w] = ans;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp, -1, sizeof(dp));
    memset(psa, 0, sizeof(psa));
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {cin >> arr[i].k;}
    for(int i = 1; i <= N; i++) {cin >> arr[i].p;}
    for(int i = 1; i <= N; i++) {cin >> arr[i].f;}
    sort(arr+1, arr+N+1, compP);
    for(int i = 1; i <= N; i++) {arr[i].p = i;}
    sort(arr+1, arr+N+1, compK);
    for(int i = 1; i <= N; i++) {psa[i] = psa[i-1]+arr[i].f;}
    cout << fun(1,N,0) << endl;
    return 0;
}