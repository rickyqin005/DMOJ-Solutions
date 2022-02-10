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
ll dp[5001];
bool vis[5001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    int N,M; cin >> N >> M;
    vis[0] = 1;
    for(int i = 1,n,v,p,pow; i <= N; i++) {
        cin >> n >> v >> p;
        for(int j = n-1, pow = 1, grp = pow; pow <= n; pow <<= 1, grp = min(j,pow), j -= grp) {
            if((ll)v*grp <= (ll)5000) {
                for(int k = 5000-v*grp; k >= 0; k--) {
                    if(vis[k]) {
                        dp[k+v*grp] = max(dp[k+v*grp], dp[k]+(ll)p*grp);
                        vis[k+v*grp] = 1;
                    }
                }
            }
        }
    }
    for(int i = 1; i <= 5000; i++) {
        dp[i] = max(dp[i], dp[i-1]);
    }
    ll ans = INT_MIN;
    for(int i = 1,c,f; i <= M; i++) {
        cin >> c >> f;
        ans = max(ans, dp[c]-f);
    }
    cout << ans << "\n";

    return 0;
}