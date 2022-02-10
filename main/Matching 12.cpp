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
bool arr[22][22];
int dp[1<<21];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(arr, 0, sizeof(arr));
    memset(dp, 0, sizeof(dp));
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) cin >> arr[i][j];
    }
    int N2 = (1<<N);
    for(int j = 1; j <= N; j++) dp[1<<(N-j)] = arr[1][j];
    for(int i = 2; i <= N; i++) {
        for(int k = N2-1; k >= 0; k--) {
            if(dp[k]) {
                for(int j = 1; j <= N; j++) {
                    if(arr[i][j] && !((k>>(N-j))&1)) {
                        dp[k|(1<<(N-j))] += dp[k];
                        dp[k|(1<<(N-j))] %= MOD;
                    }
                }
                dp[k] = 0;
            }
        }
    }
    cout << dp[N2-1] << "\n";
    return 0;
}