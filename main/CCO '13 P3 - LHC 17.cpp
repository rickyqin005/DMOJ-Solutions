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
typedef pair<int, ll> pil;
int N;
vector<int> adj[400001];
int dis[400001];
int diameterLength = -1;
int diameterStart = -1, diameterEnd = -1;
int minTreeHeight = INT_MAX;
pii center = mp(-1,-1);
vector<ll> branch1;
void dfs1(int curr, int par, int depth) {
    for(int next: adj[curr]) {
        if(next == par) continue;
        dfs1(next, curr, depth+1);
    }
    if(depth > diameterLength) {
        diameterLength = depth;
        diameterStart = curr;
    }
}
void dfs2(int curr, int par, int depth) {
    for(int next: adj[curr]) {
        if(next == par) continue;
        dfs2(next, curr, depth+1);
    }
    dis[curr] = depth;
    if(depth > diameterLength) {
        diameterLength = depth;
        diameterEnd = curr;
    }
}
void dfs3(int curr, int par, int depth) {
    for(int next: adj[curr]) {
        if(next == par) continue;
        dfs3(next, curr, depth+1);
    }
    dis[curr] = max(dis[curr], depth);
    if(dis[curr] < minTreeHeight) {
        minTreeHeight = dis[curr];
        center = mp(curr, -1);
    } else if(dis[curr] == minTreeHeight) center.s = curr;
}
pil dfs4(int curr, int par) {
    pil ans = mp(0,1);
    for(int next: adj[curr]) {
        if(next == par) continue;
        pii res = dfs4(next, curr);
        if(res.f > ans.f) ans = res;
        else if(res.f == ans.f) ans.s += res.s;
    }
    ans.f++;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i = 1,u,v; i < N; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs1(1, -1, 0);
    diameterLength = -1;
    dfs2(diameterStart, -1, 0);
    dfs3(diameterEnd, -1, 0);

    ll ans = 0;
    if(center.s == -1) {//one center
        ll sum = 0;
        for(int next: adj[center.f]) {
            pil res = dfs4(next, center.f);
            if(res.f != diameterLength/2) continue;
            branch1.pb(res.s);
            sum += res.s;
        }
        for(ll br: branch1) {
            sum -= br;
            ans += br*sum;
        }
    } else {//two centers
        ll sum1 = dfs4(center.f, center.s).s;
        ll sum2 = dfs4(center.s, center.f).s;
        ans = sum1*sum2;
    }
    cout << diameterLength+1 << " " << ans << "\n";
    return 0;
}
