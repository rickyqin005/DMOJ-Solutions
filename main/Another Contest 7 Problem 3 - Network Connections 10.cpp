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
vector<int> adj[100001];
pii arr[100001];
bool vis[100001];
int par[100001];
int wei[100001];
bool comp(pii a, pii b) {return a.f < b.f;}
class Comp {
public: bool operator()(pipii a, pipii b) {return a.f > b.f;}
};
int get(int a) {
    if(par[a] != a) par[a] = get(par[a]);
    return par[a];
}
int join(int a, int b) {
    a = get(a); b = get(b);
    if(a != b) {
        if(wei[a] > wei[b]) {
            par[b] = a;
            wei[a] += wei[b]+1;
        } else {
            par[a] = b;
            wei[b] += wei[a]+1;
        }
        return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(vis, 0, sizeof(vis));
    memset(par, 0, sizeof(par));
    memset(wei, 0, sizeof(wei));
    int N, M; cin >> N >> M;
    for(int i = 1,f; i <= N; i++) {
        cin >> f; arr[i] = mp(f,i);
    }
    sort(arr+1, arr+N+1, comp);
    for(int i = 1,u,v; i <= M; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int cnt = 0;
    queue<int> q;
    for(int i = 1; i <= N; i++) {
        if(vis[i]) continue;
        cnt++;
        vis[i] = true;
        q.push(i); par[i] = i;
        while(!q.empty()) {
            int curr = q.front(); q.pop();
            for(int j: adj[curr]) {
                if(vis[j]) continue;
                vis[j] = true;
                q.push(j);
                par[j] = i;
            }
        }
    }
    priority_queue<pipii, vector<pipii>, Comp> pq;
    for(int i = 2; i <= N; i++) {
        if(par[arr[i].s] != par[arr[i-1].s]) {
            pq.push(mp(abs(arr[i].f-arr[i-1].f), mp(par[arr[i].s], par[arr[i-1].s])));
        }
    }
    int ans = 0;
    while(!pq.empty() && cnt > 1) {
        pipii curr = pq.top(); pq.pop();
        if(join(curr.s.f, curr.s.s)) {
            cnt--;
            ans += curr.f;
        }
    }
    cout << ans << "\n";
    return 0;
}