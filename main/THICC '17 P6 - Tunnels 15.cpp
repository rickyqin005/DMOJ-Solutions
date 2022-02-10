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
int maxd = -1, maxn = -1;
vector<pii> adj[200001];
int dis[2][200001];
void dfs1(int curr, int prev, int dist) {
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
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dis, 0, sizeof(dis));
    int N,T; cin >> N >> T;
    int sum = 0;
    for(int i = 1,a,b,c; i < N; i++) {
        cin >> a >> b >> c;
        adj[a].pb(mp(b,c));
        adj[b].pb(mp(a,c));
        sum += c;
    }
    sum *= 2;
    dfs1(1,-1, 0);
    maxd = -1;
    dfs2(maxn, -1, 0);
    dfs2(maxn, -1, 1);
    for(int i = 1; i <= N; i++) {
        if(adj[i].size() == T) cout << i << " " << sum-max(dis[0][i], dis[1][i]) << "\n";
    }
    return 0;
}
