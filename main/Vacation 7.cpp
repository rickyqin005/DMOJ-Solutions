#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int N; cin >> N;
    int dp[N][3];
    cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
    for(int i = 1,a,b,c; i < N; i++) {
        cin >> a >> b >> c;
        dp[i][0] = max(dp[i-1][1], dp[i-1][2])+a;
        dp[i][1] = max(dp[i-1][0], dp[i-1][2])+b;
        dp[i][2] = max(dp[i-1][0], dp[i-1][1])+c;
    }
    cout << max(dp[N-1][0], max(dp[N-1][1], dp[N-1][2])) << "\n";
    return 0;
}