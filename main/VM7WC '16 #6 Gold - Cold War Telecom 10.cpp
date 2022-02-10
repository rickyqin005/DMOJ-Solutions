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
vector<int> adj[100002];
int disc[100002];
int low[100002];
int order = 1;
vector<int> artic;
void tarjan(int u, int p) {
    bool ap = 0;
    int child = 0;
    disc[u] = low[u] = order;
    order++;
    for(int v: adj[u]) {
        if(v == p) continue;
        if(!disc[v]) {
            child++;
            tarjan(v,u);
            if(low[v] >= disc[u]) ap = 1;
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], disc[v]);
        }
    }
    if((u == 1 && child > 1) || (u != 1 && ap)) artic.pb(u);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(disc, 0, sizeof(disc));
    memset(low, 0x7f, sizeof(low));
    int N,M; cin >> N >> M;
    for(int i = 1,u,v; i <= M; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    tarjan(1,0);
    sort(artic.begin(), artic.end());
    cout << artic.size() << "\n";
    for(int u: artic) {
        cout << u << "\n";
    }
    return 0;
}