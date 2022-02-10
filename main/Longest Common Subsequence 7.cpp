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
typedef pair<pii, int> piipi;
typedef vector<int> vii;
typedef vector<ll> vll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int N, M; cin >> N >> M;
    int arr1[N+1];
    for(int i = 1; i <= N; i++) {cin >> arr1[i];}
    int dp[2][N+1];
    memset(dp,0,sizeof(dp));
    for(int i = 1,m; i <= M; i++) {
        cin >> m;
        for(int j = 1; j <= N; j++) {
            if(arr1[j] == m) {
                dp[i%2][j] = dp[!(i%2)][j-1]+1;
            } else {
                dp[i%2][j] = max(dp[i%2][j-1], dp[!(i%2)][j]);
            }
        }
        //for(int j = 0; j <= N; j++) {cout << dp[i%2][j] << " ";} cout << "\n";
    }
    int ans = 0;
    for(int i = 0; i <= N; i++) {ans = max(ans, dp[M%2][i]);}
    cout << ans << "\n";
    return 0;
}