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
typedef pair<pii, int> piipi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef unordered_set<int> u_si;
typedef unordered_map<string, int> u_msi;

#define MAXN 200000
int N, M;
vector<pii> adj[MAXN+1];
pii dis[MAXN+1];
bool inQ[MAXN+1];
int train[MAXN+1];
class Comp {
public:
    bool operator()(int a, int b) {
        return dis[a].f > dis[b].f;
    }
};
bool comp2(pii a, pii b) {
    return a.f < b.f;
}
priority_queue<int, vi, Comp> pq;
void dijkstra(int A) {
    dis[A].f = 1;
    pq.push(A);
    int d;
    while(!pq.empty()) {
        int curr = pq.top();
        pq.pop();
        inQ[curr] = false;
        for(pii edge: adj[curr]) {
            d = max(dis[curr].f, edge.f);
            if(d < dis[edge.s].f) {
                dis[edge.s].f = d;
                if(!inQ[edge.s]) {
                    pq.push(edge.s);
                    inQ[edge.s] = true;
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        cin >> train[i];
        dis[i].f = MAX_INT;
        dis[i].s = i;
        inQ[i] = false;
    }
    for(int i = 0,a,b,c; i < M; i++) {
        cin >> a >> b >> c;
        adj[a].pb(mp(c,b));
        adj[b].pb(mp(c,a));
    }
    dijkstra(1);
    if(dis[N].f == MAX_INT) {
        cout << -1 << "\n";
        return 0;
    }
    sort(dis+1, dis+N+1, comp2);
    //for(int i = 1; i <= N; i++) {cout << dis[i].f << " ";} cout << "\n";
    int minTrain = train[1];
    int prev = 1;
    ll ans = 0;
    for(int i = 1; i <= N; i++) {
        ans += (ll)(dis[i].f-prev)*minTrain;
        prev = dis[i].f;
        minTrain = min(minTrain, train[dis[i].s]);
        if(dis[i].s == N) break;
    }
    cout << ans << "\n";
    return 0;
}