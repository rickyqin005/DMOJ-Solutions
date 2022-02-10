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
typedef pair<pii, int> ppiii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef unordered_set<int> u_si;
typedef unordered_map<string, int> u_msi;

#define MAXN 1600
#define MAXS 3600
int S, N, E;
vector<ppiii> adj[MAXN+1];
int dis[MAXN+1][MAXS+1];
bool inQ[MAXN+1][MAXS+1];
class Comp {
public:
    bool operator()(pii a, pii b) {
        return a.f > b.f;
    }
};
priority_queue<pii, vector<pii>, Comp> pq;
void dijkstra(int A, int B) {
    for(int i = 0; i <= MAXN; i++) {
        fill_n(dis[i], MAXS+1, MAX_INT);
        fill_n(inQ[i], MAXS+1, false);
    }
    dis[A][0] = 0;
    pq.push(mp(0, A));
    int d,s;
    while(!pq.empty()) {
        pii curr = pq.top();
        pq.pop();
        inQ[curr.s][curr.f] = false;
        for(ppiii edge: adj[curr.s]) {
            d = dis[curr.s][curr.f] + edge.f.f;
            s = curr.f + (edge.f.s==1?edge.f.f:0);
            if(s > S) continue;
            //cout << curr << "  " << edge.s << "  " << d << "  " << s << "\n";
            if(d < dis[edge.s][s]) {
                dis[edge.s][s] = d;
                if(!inQ[edge.s][s]) {
                    pq.push(mp(s, edge.s));
                    inQ[edge.s][s] = true;
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> S >> N >> E;
    for(int i = 0,s,t,d,u; i < E; i++) {
        cin >> s >> t >> d >> u;
        s++; t++;
        adj[s].pb(mp(mp(d,u),t));
        adj[t].pb(mp(mp(d,u),s));
    }
    dijkstra(1, N);
    int ans = MAX_INT;
    for(int i = 0; i <= S; i++) {
        ans = min(ans, dis[N][i]);
    }
    //for(int i = 0; i <= S; i++) {cout << dis[N][i] << " ";} cout << "\n";
    if(ans == MAX_INT) cout << -1 << "\n";
    else cout << ans << "\n";
    return 0;
}