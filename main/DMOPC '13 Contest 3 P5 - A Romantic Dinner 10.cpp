#include<bits/stdc++.h>
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

#define MAXM 300
#define MAXU 100
#define MAXR 150

int dp[MAXM+1][MAXU+1];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    int M, U, R; cin >> M >> U >> R;
    for(int i = 0,V,T,F; i < R; i++) {
        cin >> V >> T >> F;
        for(int j = M-T; j >= 0; j--) {
            for(int k = U-F; k >= 0; k--) {
                if(dp[j][k] != -1) {
                    dp[j+T][k+F] = max(dp[j+T][k+F], dp[j][k]+V);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= M; i++) {
        for(int j = 0; j <= U; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
}