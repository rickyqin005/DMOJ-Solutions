#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    int stone[N];
    for(int i = 0; i < N; i++) cin >> stone[i];
    int dp[N]; fill_n(dp, N, 2000000000);
    dp[0] = 0;
    for(int i = 0; i < N-2; i++) {
        dp[i+1] = min(dp[i+1],dp[i]+abs(stone[i]-stone[i+1]));
        dp[i+2] = min(dp[i+2],dp[i]+abs(stone[i]-stone[i+2]));
    }
    dp[N-1] = min(dp[N-1], dp[N-2]+abs(stone[N-2]-stone[N-1]));
    cout << dp[N-1] << "\n";
    return 0;
}