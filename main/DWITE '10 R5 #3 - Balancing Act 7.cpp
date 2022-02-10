#include <bits/stdc++.h>
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
typedef pair<pii, int> piipi;
typedef vector<int> vii;
typedef vector<ll> vll;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i = 0; i < 5; i++) {
        int N; cin >> N;
        int len = 1000*N;
        int sum = 0;
        bool dp[len+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int j = 1,w; j <= N; j++) {
            cin >> w;
            sum += w;
            for(int k = len-w; k >= 0; k--) {
                if(dp[k]) dp[k+w] = 1;
            }
        }
        int ans = INT_MAX;
        for(int j = 0; j <= sum; j++) {
            if(dp[j]) ans = min(ans, abs(j-(sum-j)));
        }
        cout << ans << "\n";
    }
    return 0;
}