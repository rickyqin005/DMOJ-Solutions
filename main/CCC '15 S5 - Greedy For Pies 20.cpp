#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 888888877777777
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;
const int INF = 0x7f7f7f7f;
int pin[3001];
int pim[101];
int dp[3001][101][101][2];
int pfx[101];
int sum(int l, int r) {return pfx[r]-pfx[l-1];}
int solve(int n, int m1, int m0, int take) {
    if(n < 0 || m1 < 0 || m0 < 0) return -INF;
    if(dp[n][m1][m0][take] != -1) return dp[n][m1][m0][take];
    if(take == 1) {
        dp[n][m1][m0][take] = max(dp[n][m1][m0][take], solve(n-1,m1,m0,0)+pin[n]);
        dp[n][m1][m0][take] = max(dp[n][m1][m0][take], solve(n,m1-1,m0,0)+pim[m1]);
    } else {
        dp[n][m1][m0][take] = max(dp[n][m1][m0][take], solve(n,m1,m0-1,0));
        dp[n][m1][m0][take] = max(dp[n][m1][m0][take], solve(n,m1,m0-1,1));
        dp[n][m1][m0][take] = max(dp[n][m1][m0][take], solve(n-1,m1,m0,0));
        dp[n][m1][m0][take] = max(dp[n][m1][m0][take], solve(n-1,m1,m0,1));
    }
    if(dp[n][m1][m0][take] < 0) dp[n][m1][m0][take] = -INF;
    return dp[n][m1][m0][take];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp, -1, sizeof(dp));
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> pin[i];
    int M; cin >> M;
    for(int i = 1; i <= M; i++) cin >> pim[i];
    sort(pim+1, pim+M+1, greater<int>());
    pfx[0] = 0;
    for(int i = 1; i <= M; i++) pfx[i] = pfx[i-1]+pim[i];
    dp[0][0][0][0] = 0;
    int ans = 0;
    for(int j = 0,k = M; j <= M; j++,k--) {
        ans = max(max(ans, solve(N,j,k,0)), solve(N,j,k,1));
    }
    cout << ans << "\n";
    return 0;
}