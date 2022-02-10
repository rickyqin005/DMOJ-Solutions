#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef unordered_set<int> u_si;
typedef unordered_map<string, int> u_msi;

#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807
#define MAXN 100000
vector<piipi> adj[MAXN+1];//(time, station, level)
ll dis[MAXN+1];
bool vis[MAXN+1];
int A, B;
ll C;
class comp {
public:
    bool operator()(int a, int b) {
        return dis[a] > dis[b];//greater
    }
};
priority_queue<int, vector<int>, comp> pq;
bool dijkstra(int M) {
    for(int i = 0; i <= MAXN; i++) {
        dis[i] = MAX_LONG;
        vis[i] = false;
    }
    dis[A] = 0;
    pq.push(A);
    ll dist;
    while(!pq.empty()) {
        int curr = pq.top();
        pq.pop();
        vis[curr] = false;
        for(piipi edge: adj[curr]) {
            if(edge.f.s > M) continue;
            dist = dis[curr]+edge.f.f;
            if(dist >= C) continue;
            if(dist < dis[edge.s]) {
                dis[edge.s] = dist;
                if(!vis[edge.s]) {
                    pq.push(edge.s);
                    vis[edge.s] = true;
                }
            }
        }
    }
    if(dis[B] == MAX_LONG) return false;
    else return true;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int N, M; cin >> N >> M;
    for(int i = 1,a,b,c; i <= M; i++) {
        cin >> a >> b >> c;
        adj[a].pb(mp(mp(c,i),b));
        adj[b].pb(mp(mp(c,i),a));
    }
    cin >> A >> B >> C;
    int low = 1, high = M+1, mid = 0, ans = MAX_INT;
    while(low < high) {
        mid = (low+high)/2;
        if(dijkstra(mid)) {
            high = mid;
            ans = min(ans, mid);
        } else {
            low = mid+1;
        }
    }
    if(ans == MAX_INT) cout << -1 << "\n";
    else cout << ans << "\n";
}
