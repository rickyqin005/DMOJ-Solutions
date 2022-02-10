#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807
#define MAX_DOUBLE 1e18
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, double> pid;
typedef pair<double, int> pdi;
typedef pair<pii, pii> ppiipii;
typedef vector<int> vii;
typedef vector<ll> vll;
#define MAXN 100000
int N, M, L, ans = 0;
vector<pii> adj[MAXN+1];
bool vis[MAXN+1];
int dis[MAXN+1];
int maxDis = -1, maxN = -1;
int radius = INT_MAX, cnt = 0;
int maxRadii[] = {0,0,0};
void dfs1(int curr, int prev) {
    for(pii next: adj[curr]) {
        if(next.f == prev) continue;
        dis[next.f] = dis[curr]+next.s;
        dfs1(next.f, curr);
    }
    if(dis[curr] > maxDis) {
        maxDis = dis[curr];
        maxN = curr;
    }
}
void dfs2(int curr, int d) {
    for(pii next: adj[curr]) {
        if(vis[next.f]) continue;
        vis[next.f] = true;
        dfs2(next.f, d+next.s);
    }
    radius = min(radius, max(d,dis[curr]));
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    memset(vis, 0, sizeof(vis));
    cin >> N >> M >> L;
    for(int i = 1,a,b,t; i <= M; i++) {
        cin >> a >> b >> t;
        a++; b++;
        adj[a].pb(mp(b,t));
        adj[b].pb(mp(a,t));
    }
    for(int i = 1; i <= N; i++) {
        if(vis[i]) continue;
        maxDis = -1;
        dfs1(i,-1);
        maxDis = -1;
        dis[maxN] = 0;
        dfs1(maxN,-1);
        ans = max(ans, maxDis);
        radius = INT_MAX;
        vis[maxN] = true;
        dfs2(maxN,0);
        if(radius >= maxRadii[0]) {
            maxRadii[2] = maxRadii[1];
            maxRadii[1] = maxRadii[0];
            maxRadii[0] = radius;
        } else if(radius >= maxRadii[1]) {
            maxRadii[2] = maxRadii[1];
            maxRadii[1] = radius;
        } else if(radius >= maxRadii[2]) {
            maxRadii[2] = radius;
        }
        cnt++;
    }
    if(cnt >= 2) ans = max(ans, maxRadii[0]+maxRadii[1]+L);
    if(cnt >= 3) ans = max(ans, maxRadii[1]+maxRadii[2]+2*L);
    cout << ans << "\n";
    return 0;
}