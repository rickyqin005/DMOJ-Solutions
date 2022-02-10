#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;
vector<int> adjr[300001];
bool vis[300001];
int ans[300001];
int start;
void dfs(int a) {
    for(int b: adjr[a]) {
        if(vis[b]) continue;
        vis[b] = 1;
        ans[b] = start;
        dfs(b);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N,M; cin >> N >> M;
    for(int i = 1,u,v; i <= M; i++) {
        cin >> u >> v;
        adjr[v].pb(u);
    }
    memset(vis, 0, sizeof(vis));
    memset(ans, 0, sizeof(ans));
    for(int i = N; i >= 1; i--) {
        if(vis[i]) continue;
        start = i;
        vis[i] = 1;
        dfs(i);
    }
    for(int i = N-1; i >= 1; i--) {
        if(i < ans[i]) {
            cout << i << " " << ans[i] << "\n"; exit(0);
        }
    }
    cout << -1 << "\n";
    return 0;
}