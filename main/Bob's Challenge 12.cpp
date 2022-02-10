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
#define MOD 1000000007
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef vector<int> vii;
typedef vector<ll> vll;
int dp[1000001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    int N; cin >> N;
    for(int i = 1; i <= N; i <<= 1) {
        for(int j = 0; j <= N-i; j++) {
            dp[j+i] = (dp[j+i]+dp[j])%MOD;
        }
    }
    cout << dp[N] << "\n";
    //for(int i = 1; i <= N; i++) {cout << dp[i] << " ";} cout << "\n";
    return 0;
}