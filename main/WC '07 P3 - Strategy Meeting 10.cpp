#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 13371337
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef pair<int, pii> pipii;
int dp[16][1<<15];
bool adj[16][16];
queue<pii> q;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int t = 1; t <= T; t++) {
        memset(dp, 0, sizeof(dp));
        memset(adj, 0, sizeof(adj));
        int N; cin >> N;
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) cin >> adj[i][j];
        }
        dp[1][1<<(N-1)] = 1;
        q.push(mp(1,1<<(N-1)));
        while(!q.empty()) {
            pii curr = q.front(); q.pop();
            for(int i = 2; i <= N; i++) {
                if(adj[curr.f][i] && !((curr.s>>(N-i))&1)) {
                    if(!dp[i][curr.s|(1<<(N-i))]) q.push(mp(i,curr.s|(1<<(N-i))));
                    dp[i][curr.s|(1<<(N-i))] += dp[curr.f][curr.s];
                    dp[i][curr.s|(1<<(N-i))] %= MOD;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < (1<<N); i++) {
            ans += dp[N][i];
            ans %= MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}