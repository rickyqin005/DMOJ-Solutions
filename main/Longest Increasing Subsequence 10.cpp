#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int dp[1000001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp, 0x7f, sizeof(dp));
    dp[0] = INT_MIN;
    int N; cin >> N;
    for(int i = 1,a; i <= N; i++) {
        cin >> a;
        *lower_bound(dp, dp+N+1, a) = a;
    }
    cout << lower_bound(dp, dp+N+1, 0x7f7f7f7f)-dp-1 << "\n";
    return 0;
}