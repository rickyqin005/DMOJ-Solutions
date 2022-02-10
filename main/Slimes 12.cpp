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
int arr[401];
ll dp[401][401];
ll psa[401];
ll sum(int l, int r) {return psa[r]-psa[l-1];}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp, 0x7f, sizeof(dp));
    memset(psa, 0, sizeof(psa));
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        dp[i][i] = 0;
        psa[i] = psa[i-1]+arr[i];
    }
    for(int len = 1; len < N; len++) {
        for(int l = 1, r = l+len; r <= N; l++, r++) {
            for(int k = l; k < r; k++) {
                dp[l][r] = min(dp[l][r], dp[l][k]+dp[k+1][r]+sum(l,r));
            }
        }
    }
    cout << dp[1][N] << "\n";
    return 0;
}