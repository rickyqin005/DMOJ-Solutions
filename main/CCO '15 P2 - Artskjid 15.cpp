#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef pair<int, pii> pipii;
int dis[19][1<<18];
int adj[19][19];
queue<pii> q;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dis, -1, sizeof(dis));
    memset(adj, 0, sizeof(adj));
    int N,M; cin >> N >> M;
    for(int i = 1,a,b,l; i <= M; i++) {
        cin >> a >> b >> l;
        adj[a+1][b+1] = l;
    }
    dis[1][1<<(N-1)] = 0;
    q.push(mp(1,1<<(N-1)));
    while(!q.empty()) {
        pii curr = q.front(); q.pop();
        for(int i = 2; i <= N; i++) {
            if(adj[curr.f][i] && !((curr.s>>(N-i))&1)) {
                if(dis[i][curr.s|1<<(N-i)] == -1) q.push(mp(i,curr.s|1<<(N-i)));
                dis[i][curr.s|1<<(N-i)] = max(dis[i][curr.s|1<<(N-i)], dis[curr.f][curr.s]+adj[curr.f][i]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < (1<<N); i++) ans = max(ans, dis[N][i]);
    cout << ans << endl;
    return 0;
}