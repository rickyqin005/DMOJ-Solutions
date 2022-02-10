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
vector<int> adj[500001];
int arr[500001];
ll finalAns = 0;
ll dfs(int curr, int par) {
    if(curr != 1 && adj[curr].size() == 1) return arr[curr];
    vector<ll> cost;
    for(int next: adj[curr]) {
        if(next == par) continue;
        cost.pb(dfs(next, curr));
    }
    sort(cost.begin(), cost.end(), greater<ll>());
    //for(int c: cost) {cout << c << " ";} cout << "\n";
    ll ans = 0;
    for(int i = (curr==1?3:2); i < cost.size(); i++) finalAns += cost[i];
    for(int i = 0; i < (curr==1?3:2) && i < cost.size(); i++) ans += cost[i];
    ans += arr[curr];
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i = 2; i <= N; i++) cin >> arr[i];
    for(int i = 1,u,v; i < N; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, -1);
    cout << finalAns << "\n";
    return 0;
}
