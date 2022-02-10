#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef pair<int, pii> pipii;
int dp[33][7];
/*
dp[1]:  |   dp[2]:  |_      dp[3]:   _|     dp[4]:    |     dp[5]:   _|     dp[6]:  |_      dp[7]:  |
        |             |             |_               _|             |                _|             |_
        |             |               |             |               |               |                 |
*/
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int t = 1,N; t <= 5; t++) {
        memset(dp, 0, sizeof(dp));
        cin >> N;
        if(N%2 == 1) {
            cout << 0 << endl; continue;
        }
        dp[0][1] = 1;
        for(int i = 0; i <= N; i++) {
            dp[i][2] += dp[i][1]; dp[i][2] %= MOD;
            dp[i][4] += dp[i][1]; dp[i][4] %= MOD;
            dp[i+2][1] += dp[i][1]; dp[i+2][1] %= MOD;
            dp[i+1][5] += dp[i][2]; dp[i+1][5] %= MOD;
            dp[i+1][6] += dp[i][3]; dp[i+1][6] %= MOD;
            dp[i+1][7] += dp[i][4]; dp[i+1][7] %= MOD;
            dp[i+1][1] += dp[i][5]; dp[i+1][1] %= MOD;
            dp[i+1][2] += dp[i][5]; dp[i+1][2] %= MOD;
            dp[i+1][3] += dp[i][6]; dp[i+1][3] %= MOD;
            dp[i+1][1] += dp[i][7]; dp[i+1][1] %= MOD;
            dp[i+1][4] += dp[i][7]; dp[i+1][4] %= MOD;
            //for(int j = 1; j <= 7; j++) {cout << dp[i][j] << " ";} cout << endl;
        }
        cout << dp[N][1] << endl;
    }
    return 0;
}