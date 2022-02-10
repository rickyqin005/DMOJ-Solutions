#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int A, B, N; cin >> A >> B >> N;
    int motel[14+N] = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
    for(int i = 0; i < N; i++) {
        cin >> motel[14+i];
    }
    sort(motel, motel+14+N);
    ll dp[14+N] = {0};
    dp[0] = 1;
    for(int i = 0; i < 14+N; i++) {
        for(int j = i+1; j < 14+N; j++) {
            if(motel[j]-motel[i] >= A && motel[j]-motel[i] <= B) dp[j] += dp[i];
        }
    }
    cout << dp[14+N-1] << "\n";
    return 0;
}