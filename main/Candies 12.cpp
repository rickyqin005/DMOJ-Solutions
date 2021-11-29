#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef vector<int> vii;
typedef vector<ll> vll;
int arr[101];
int dp[101][100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    int N,K; cin >> N >> K;
    for(int i = 1; i <= N; i++) {cin >> arr[i];}
    int maxc = 0; ll sum = 0;
    for(int i = 1; i <= N; i++) {
        maxc += arr[i]; sum = 0;
        for(int j = 0; j <= min(maxc,K); j++) {
            sum += dp[i-1][j];
            if(j > arr[i]) sum -= dp[i-1][j-arr[i]-1];
            dp[i][j] = (int)(sum%MOD);
        }
    }
    cout << dp[N][K] << "\n";
    return 0;
}