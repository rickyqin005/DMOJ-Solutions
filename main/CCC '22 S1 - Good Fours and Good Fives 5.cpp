#include <bits/stdc++.h>
using namespace std;
int dp[1000001];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    memset(dp, 0, sizeof(dp));
    int N; cin >> N;
    dp[0] = 1;
    for(int i = 0; i <= N-4; i++) dp[i+4] += dp[i];
    for(int i = 0; i <= N-5; i++) dp[i+5] += dp[i];
    cout << dp[N] << "\n";
    return 0;
}