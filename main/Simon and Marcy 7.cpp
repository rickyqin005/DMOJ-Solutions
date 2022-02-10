#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int C, M; cin >> C >> M;
    int dp[M+1];
    fill_n(dp, M+1, 0);

    for(int i = 0,N,K; i < C; i++) {
        cin >> N >> K;
        for(int j = M-K; j > 0; j--) {
            if(dp[j] != 0) {
                dp[j+K] = max(dp[j+K], dp[j]+N);
            }
        }
        if(dp[K] == 0) dp[K] = N;
        else dp[K] = max(dp[K], N);
    }
    int ans = 0;
    for(int i = M; i >= 0; i--) {
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
}