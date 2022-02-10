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
typedef pair<pii, int> piipi;
typedef vector<int> vii;
typedef vector<ll> vll;
#define MAXN 1000
int N, M;
vector<pii> adj[MAXN+1];
int dis[MAXN+1];
bool vis[MAXN+1];
class Comp {
public:
    bool operator()(pii a, pii b) {
        return a.s > b.s;
    }
};
priority_queue<pii, vector<pii>, Comp> pq;
void dijkstra(int A) {
    dis[A] = 0;
    pq.push(mp(A,0));
    pii curr; int d;
    while(!pq.empty()) {
        curr = pq.top(); pq.pop();
        if(vis[curr.f]) continue;
        vis[curr.f] = 1;
        for(pii next: adj[curr.f]) {
            d = dis[curr.f]+next.s;
            if(d < dis[next.f]) {
                dis[next.f] = d;
                pq.push(mp(next.f,d));
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dis, 0x7f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    cin >> N >> M;
    for(int i = 0,u,v,w; i < M; i++) {
        cin >> u >> v >> w;
        adj[u].pb(mp(v,w));
        adj[v].pb(mp(u,w));
    }
    dijkstra(1);
    for(int i = 1; i <= N; i++) {cout << ((dis[i] == 0x7f7f7f7f)?-1:dis[i]) << "\n";}
    return 0;
}