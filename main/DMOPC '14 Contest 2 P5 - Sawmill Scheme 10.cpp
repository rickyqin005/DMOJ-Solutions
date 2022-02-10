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
vector<int> adj[1000001];
double dp[1000001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp, 0, sizeof(dp));
    int N,M; cin >> N >> M;
    for(int i = 1,a,b; i <= M; i++) {
        cin >> a >> b;
        adj[a].pb(b);
    }
    dp[1] = 1;
    for(int i = 1; i <= N; i++) {
        for(int j: adj[i]) {
            dp[j] += dp[i]/adj[i].size();
        }
        if(adj[i].size() == 0) printf("%.012f\n", dp[i]);
    }
    return 0;
}