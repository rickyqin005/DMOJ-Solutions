#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int N, T; cin >> N >> T;
    int dp[T+1];
    fill_n(dp, T+1, -1);
    dp[0] = 0;
    for(int i = 0,v,h; i < N; i++) {
        cin >> v >> h;
        for(int j = T-h; j >= 0; j--) {
            if(dp[j] != -1) dp[j+h] = max(dp[j+h], dp[j]+v);
        }
    }
    int ans = 0;
    for(int i = 0; i <= T; i++) {ans = max(ans, dp[i]);}
    cout << ans << "\n";
    return 0;
}