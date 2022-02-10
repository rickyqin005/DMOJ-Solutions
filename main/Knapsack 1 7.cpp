#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, W; cin >> N >> W;
    ll dp[W+1] = {0};
    ll w, v;
    for(int i = 0; i < N; i++) {
        cin >> w >> v;
        for(int j = W-w; j > 0; j--) {
            if(dp[j] != 0) {
                dp[j+w] = max(dp[j+w], dp[j]+v);
            }
        }
        dp[w] = max(dp[w], v);
    }
    ll ans = 0;
    for(int i = 1; i <= W; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
}