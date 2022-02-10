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
#define MOD 1000000007
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef vector<int> vii;
typedef vector<ll> vll;
#define MAXN 200001
int N, M, K;
int cnt = 0;
vii adj[MAXN];
int dis[2][MAXN];
bool vis[2][MAXN];
queue<int> q;
void bfs(int A, int idx) {
    q.push(A); int curr;
    dis[idx][A] = 0;
    vis[idx][A] = true;
    while(!q.empty()) {
        curr = q.front(); q.pop();
        for(int next: adj[curr]) {
            if(vis[idx][next]) continue;
            vis[idx][next] = true;
            dis[idx][next] = dis[idx][curr]+1;
            if(dis[idx][next] < K) {
                q.push(next);
            }
        }
    }
}

ll power(int a) {
    ll ans = 1;
    for(int i = 1; i <= a; i++) {
        ans = (ans*2)%MOD;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    cin >> N >> M >> K;
    for(int i = 0,a,b; i < M; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bfs(1,0);
    bfs(N,1);
    for(int i = 1; i <= N; i++) {
        if(vis[0][i] && vis[1][i]) cnt++;
    }
    cnt -= 2;
    cout << power(cnt) << "\n";
    return 0;
}