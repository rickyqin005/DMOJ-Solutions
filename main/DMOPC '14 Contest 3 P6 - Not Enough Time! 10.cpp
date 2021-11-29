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

#define MAXT 10000
ll dp[2][MAXT+1];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int N, T; cin >> N >> T;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = dp[1][0] = 0;
    for(int i = 1,pp,vp,pa,va,pg,vg; i <= N; i++) {
        cin >> pp >> vp >> pa >> va >> pg >> vg;
        for(int j = T; j >= 0; j--) {
            dp[i%2][j] = max(dp[!(i%2)][j],
                    max((j-pp < 0)?-1:((dp[!(i%2)][j-pp] == -1)?-1:(dp[!(i%2)][j-pp]+vp)),
                    max((j-pa < 0)?-1:((dp[!(i%2)][j-pa] == -1)?-1:(dp[!(i%2)][j-pa]+va)),
                        (j-pg < 0)?-1:((dp[!(i%2)][j-pg] == -1)?-1:(dp[!(i%2)][j-pg]+vg)))));
        }
    }
    ll ans = 0;
    for(int i = 0; i <= T; i++) ans = max(ans, dp[N%2][i]);
    cout << ans << "\n";
    return 0;
}