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
ll slot[102][5];
ll dp[100002];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp, 0, sizeof(dp));
    ll N,C; cin >> N >> C;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= 4; j++) cin >> slot[i][j];
    }
    for(int i = 1; i <= N; i++) {
        for(int k = C; k >= 0; k--) {
            if(k+slot[i][1] <= C && dp[k] != 0) dp[k+slot[i][1]] = max(dp[k+slot[i][1]], dp[k]+slot[i][2]);
            if(k+slot[i][3] <= C && dp[k] != 0) dp[k+slot[i][3]] = max(dp[k+slot[i][3]], dp[k]+slot[i][4]);
        }
        if(slot[i][1] <= C) dp[slot[i][1]] = max(dp[slot[i][1]], slot[i][2]);
        if(slot[i][3] <= C) dp[slot[i][3]] = max(dp[slot[i][3]], slot[i][4]);
    }
    for(int i = 1; i <= N; i++) {
        if(slot[i][1]+slot[i][3] <= C) dp[slot[i][1]+slot[i][3]] = max(dp[slot[i][1]+slot[i][3]], slot[i][2]+slot[i][4]);
        for(int k = 0; k <= C; k++) {
            if(k+slot[i][1]+slot[i][3] <= C && dp[k] != 0) dp[k+slot[i][1]+slot[i][3]] = max(dp[k+slot[i][1]+slot[i][3]], dp[k]+slot[i][2]+slot[i][4]);
        }
    }
    ll ans = 0;
    for(int i = 0; i <= C; i++) ans = max(ans, dp[i]);
    cout << ans << "\n";
    return 0;
}