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
#define MAXP 5000
ll dp[MAXP+1];
bool vis[MAXP+1];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp, 0x7f, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    dp[0] = 0;
    vis[0] = 1;
    int N; cin >> N;
    int sum = 0;
    for(int i = 0,v,p; i < N; i++) {
        cin >> v >> p;
        sum += p;
        for(int j = MAXP-p; j >= 0; j--) {
            if(vis[j]) {
                dp[j+p] = min(dp[j+p], dp[j]+v/2+1);
                vis[j+p] = 1;
            }
        }
    }
    ll ans = LONG_MAX;
    for(int i = sum/2+1; i <= sum; i++) {
        ans = min(ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
}