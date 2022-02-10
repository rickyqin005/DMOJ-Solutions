#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<int> adj[100001];
pll dfs(int curr, int par) {
    if(adj[curr].size() == 1 && curr != 1) return mp(1,1);
    pll ans = mp(1,1);
    for(int next: adj[curr]) {
        if(next == par) continue;
        pll res = dfs(next, curr);
        ans.f = (ans.f*res.f)%MOD;
        ans.s = (ans.s*(res.f+res.s))%MOD;
    }
    //cout << curr << ": " << ans.f << " " << ans.s << "\n";
    return mp(ans.s, ans.f);
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N; cin >> N;
    for(int i = 1,u,v; i < N; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    pll ans = dfs(1, -1);
    cout << (ans.f+ans.s)%MOD << "\n";
    return 0;
}