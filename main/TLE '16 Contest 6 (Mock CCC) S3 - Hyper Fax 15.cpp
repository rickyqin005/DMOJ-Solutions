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
pii a[2001];
bool comp(pii a, pii b) {return a.f < b.f;}
int dp[2][2001][2001];
int psa[2001];
int sum(int l, int r) {return psa[r]-psa[l-1];}
int dist(int l, int r) {return abs(a[l].f-a[r].f);}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp, -1, sizeof(dp));
    memset(psa, 0, sizeof(psa));
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {cin >> a[i].f >> a[i].s;}
    sort(a+1, a+N+1, comp);
    for(int i = 1; i <= N; i++) {psa[i] = psa[i-1]+a[i].s;}
    int s = lower_bound(a+1,a+N+1, mp(0,0))-a;
    dp[0][s][s] = dp[1][s][s] = a[s].s;
    for(int len = 1; len < N; len++) {
        for(int l = max(s-len,1),r = l+len; l <= s && r <= N; l++,r++) {
            if(dp[0][l+1][r] != -1) dp[0][l][r] = max(dp[0][l][r], (dp[0][l+1][r]-dist(l+1,l)>=0)?dp[0][l+1][r]-dist(l+1,l)+a[l].s:-1);
            if(dp[1][l+1][r] != -1) dp[0][l][r] = max(dp[0][l][r], (dp[1][l+1][r]-dist(r,l)>=0)?dp[1][l+1][r]-dist(r,l)+a[l].s:-1);
            if(dp[0][l][r-1] != -1) dp[1][l][r] = max(dp[1][l][r], (dp[0][l][r-1]-dist(l,r)>=0)?dp[0][l][r-1]-dist(l,r)+a[r].s:-1);
            if(dp[1][l][r-1] != -1) dp[1][l][r] = max(dp[1][l][r], (dp[1][l][r-1]-dist(r-1,r)>=0)?dp[1][l][r-1]-dist(r-1,r)+a[r].s:-1);
        }
    }
    int ans = 0;
    for(int e = 0; e <= 1; e++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(dp[e][i][j] >= 0) ans = max(ans, sum(i,j));
            }
        }
    }
    cout << ans << "\n";
    return 0;
}