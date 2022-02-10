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
int arr[201];
int dp[201][201];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(true) {
        int N; cin >> N;
        if(N == 0) break;
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= N; i++) {cin >> arr[i];}
        for(int i = 2; i < N; i++) {
            for(int j = 1, r = j+i; r <= N; j++, r++) {
                for(int k = j+1; k < r; k++) {
                    dp[j][r] = max(dp[j][r], arr[j]+arr[k]+arr[r]+dp[j][k]+dp[k][r]);
                }
            }
        }
        cout << dp[1][N] << "\n";
    }
    return 0;
}