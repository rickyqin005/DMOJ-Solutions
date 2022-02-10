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
int N,M;
int dp[51][51][51][51];
bool vis[51][51][51][51];
int pfs[51][51];
int sum(int r1, int c1, int r2, int c2) {return pfs[r2][c2]-pfs[r1-1][c2]-pfs[r2][c1-1]+pfs[r1-1][c1-1];}
int solve(int r1, int c1, int r2, int c2) {
    if(vis[r1][c1][r2][c2]) return dp[r1][c1][r2][c2];
    vis[r1][c1][r2][c2] = 1;
    if(r1 == r2 && c1 == c2) return 0;
    dp[r1][c1][r2][c2] = INT_MAX;
    for(int i = r1; i < r2; i++) {
        dp[r1][c1][r2][c2] = min(dp[r1][c1][r2][c2], solve(r1,c1,i,c2)+solve(i+1,c1,r2,c2));
    }
    for(int j = c1; j < c2; j++) {
        dp[r1][c1][r2][c2] = min(dp[r1][c1][r2][c2], solve(r1,c1,r2,j)+solve(r1,j+1,r2,c2));
    }
    dp[r1][c1][r2][c2] += sum(r1,c1,r2,c2);
    return dp[r1][c1][r2][c2];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    memset(pfs, 0, sizeof(pfs));
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) cin >> pfs[i][j];
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) pfs[i][j] += pfs[i][j-1];
    }
    for(int j = 1; j <= M; j++) {
        for(int i = 1; i <= N; i++) pfs[i][j] += pfs[i-1][j];
    }
    /*for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) cout << pfs[i][j] << " ";
        cout << "\n";
    }*/
    cout << solve(1, 1, N, M) << "\n";
    return 0;
}