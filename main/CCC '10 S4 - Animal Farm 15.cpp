#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;
int M;
vector<int> adj[101];
bool vis[101];
vector<tiii> allEdge;
int input[17];
pii edge[801][801];
int par[101];
int wei[101];
bool comp(tiii a, tiii b) {return get<2>(a) < get<2>(b);}
int get(int a) {
    if(par[a] != a) par[a] = get(par[a]);
    return par[a];
}
bool join(int a, int b) {
    a = get(a); b = get(b);
    if(a != b) {
        if(wei[a] > wei[b]) {
            par[b] = a; wei[a] += wei[b]+1;
        } else {
            par[a] = b; wei[b] += wei[a]+1;
        }
        return true;
    }
    return false;
}
bool allConnected() {
    memset(vis, 0, sizeof(vis));
    int A = 1, cnt = 1;
    queue<int> q;
    vis[A] = 1;
    q.push(A);
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        for(int i: adj[curr]) {
            if(!vis[i]) {
                vis[i] = 1;
                cnt++;
                q.push(i);
            }
        }
    }
    return (cnt == M);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(edge, -1, sizeof(edge));
    cin >> M;
    for(int i = 1,e,u,v; i <= M; i++) {
        cin >> e;
        for(int j = 1; j <= 2*e; j++) {
            cin >> input[j];
        }
        for(int j = 1; j <= e; j++) {
            u = input[j]; v = input[j%e+1];
            if(u > v) swap(u,v);
            if(edge[u][v].f != -1) {
                adj[i].pb(edge[u][v].f);
                adj[edge[u][v].f].pb(i);
                allEdge.pb(mt(edge[u][v].f,i,edge[u][v].s));
                edge[u][v].f = -1;
            } else {
                edge[u][v].f = i;
                edge[u][v].s = input[j+e];
            }
        }
    }
    int ans = INT_MAX,cost,cnt;
    if(allConnected() == 1) {
        for(int i = 1; i <= M; i++) par[i] = i;
        memset(wei, 0, sizeof(wei));
        sort(allEdge.begin(), allEdge.end(), comp);
        cost = 0; cnt = 0;
        for(tiii i: allEdge) {
            //cout << get<0>(i) << " " << get<1>(i) << " " << get<2>(i) << "\n";
            if(join(get<0>(i),get<1>(i))) {
                cost += get<2>(i);
                cnt++;
            }
            if(cnt == M-1) {
                ans = cost; break;
            }
        }
    }

    for(int i = 1; i <= 800; i++) {
        for(int j = i+1; j <= 800; j++) {
            if(edge[i][j].f != -1) {
                allEdge.pb(mt(0,edge[i][j].f,edge[i][j].s));
            }
        }
    }
    for(int i = 1; i <= M; i++) par[i] = i;
    memset(wei, 0, sizeof(wei));
    sort(allEdge.begin(), allEdge.end(), comp);
    cost = 0; cnt = 0;
    for(tiii i: allEdge) {
        if(join(get<0>(i),get<1>(i))) {
            //cout << get<0>(i) << " " << get<1>(i) << " " << get<2>(i) << "\n";
            cost += get<2>(i);
            cnt++;
        }
        if(cnt == M) break;
    }
    ans = min(ans, cost);
    cout << ans << "\n";
    return 0;
}