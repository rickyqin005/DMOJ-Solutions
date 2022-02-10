#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef pair<int, pii> pipii;
vector<pii> adj[100001];
ll dis[2][100001];
bool vis[100001];
queue<int> q;
int N,M,Q,maxn = -1; ll maxd = -1;
void dfs1(int curr, int prev, ll dist) {
    for(pii next: adj[curr]) {
        if(next.f == prev) continue;
        dfs1(next.f, curr, dist+next.s);
    }
    if(dist > maxd) {
        maxd = dist;
        maxn = curr;
    }
}
void dfs2(int curr, int prev, int idx) {
    for(pii next: adj[curr]) {
        if(next.f == prev) continue;
        dis[idx][next.f] = dis[idx][curr]+next.s;
        dfs2(next.f, curr, idx);
    }
    if(dis[idx][curr] > maxd) {
        maxd = dis[idx][curr];
        maxn = curr;
    }
    vis[curr] = true;
    if(Q == 2) q.push(curr);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    cin >> N >> M >> Q;
    for(int i = 1,u,v,c; i <= M; i++) {
        cin >> u >> v >> c;
        adj[u].pb(mp(v,c));
        adj[v].pb(mp(u,c));
    }
    ll ans = 0, cnt = 0, r;
    if(Q == 1) {
        for(int i = 1; i <= N; i++) {
            if(vis[i]) continue;
            dfs1(i,-1,0);
            maxd = -1;
            dfs2(maxn,-1,0);
            ans += maxd;
            maxd = -1;
            cnt++;
        }
        ans += cnt-1;
    } else {
        for(int i = 1; i <= N; i++) {
            if(vis[i]) continue;
            dfs1(i,-1,0);
            maxd = -1;
            dfs2(maxn,-1,0);
            dfs2(maxn,-1,1);
            maxd = -1;
            r = MAX_LONG;
            while(!q.empty()) {
                int curr = q.front(); q.pop();
                r = min(r, max(dis[0][curr], dis[1][curr]));
            }
            if(r > ans) {
                ans = r; cnt = 1;
            } else if(r == ans) cnt++;
        }
        if(cnt > 1) ans++;
    }
    cout << ans << "\n";
    return 0;
}