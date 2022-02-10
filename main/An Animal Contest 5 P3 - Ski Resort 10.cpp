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
vector<pii> adj[200001];
int N,K;
int arr[200001];
int ans[200001];
void dfs(int cur, int par, int L, int R) {
    if(L > R) return;
    ans[cur] = upper_bound(arr+1, arr+K+1, R)-lower_bound(arr+1, arr+K+1, L);
    auto it = adj[cur].begin();
    for(; it != adj[cur].end(); it++) {
        if(it->f == par) break;
    }
    adj[cur].erase(it);
    //for(pii edge: adj[cur]) {cout << edge.f << " ";} cout << "\n";
    for(int i = 0; i < adj[cur].size(); i++) {
        int l = (i==0 ? 1 : adj[cur][i].s-(adj[cur][i].s-adj[cur][i-1].s-1)/2);
        int r = (i==adj[cur].size()-1 ? 1000000000 : (adj[cur][i].s+adj[cur][i+1].s)/2);
        dfs(adj[cur][i].f, cur, max(l, L), min(r, R));
    }
}
bool comp(pii a, pii b) {return a.s < b.s;}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(ans, 0, sizeof(ans));
    cin >> N >> K;
    for(int i = 1,u,v,l; i < N; i++) {
        cin >> u >> v >> l;
        adj[u].pb(mp(v,l));
        adj[v].pb(mp(u,l));
    }
    adj[1].pb(mp(-1,1));
    for(int i = 1; i <= K; i++) cin >> arr[i];
    sort(arr+1, arr+K+1);
    for(int i = 1; i <= N; i++) sort(adj[i].begin(), adj[i].end(), comp);
    dfs(1, -1, 1, 1000000000);
    cout << ans[1];
    for(int i = 2; i <= N; i++) cout << " " << ans[i];
    cout << "\n";
    return 0;
}