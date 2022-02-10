#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
vector<int> adj[200001];
int indeg[200001];
int dis[200001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dis, 0, sizeof(dis));
    memset(indeg, 0, sizeof(indeg));
    int N,M; cin >> N >> M;
    for(int i = 1,u,v; i <= M; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        indeg[v]++;
    }
    queue<int> q;
    for(int i = 1; i <= N; i++) {
        if(indeg[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        for(int next: adj[curr]) {
            dis[next] = max(dis[next], dis[curr]+1);
            indeg[next]--;
            if(indeg[next] == 0) q.push(next);
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        ans = max(ans, dis[i]);
    }
    cout << ans << "\n";
    return 0;
}