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
int a[500001];
int dis[500001];
bool vis[500001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(a, 0, sizeof(a));
    memset(dis, 0x7f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    int N; cin >> N;
    a[1] = a[2] = 1;
    for(int i = 3; i <= N; i++) a[i] = (a[i-1]+a[i-2])%2021;
    for(int i = 1; i <= N; i++) a[i] = (a[i]%2021)+(i%50);

    queue<int> q;
    q.push(1);
    vis[1] = 1;
    dis[1] = 0;
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        if(curr == N) break;
        if(curr+1 <= N) {
            if(!vis[curr+1]) {
                vis[curr+1] = 1;
                dis[curr+1] = dis[curr]+1;
                q.push(curr+1);
            }
        }
        if(curr-1 >= 1) {
            if(!vis[curr-1]) {
                vis[curr-1] = 1;
                dis[curr-1] = dis[curr]+1;
                q.push(curr-1);
            }
        }
        if(curr+a[curr] <= N) {
            if(!vis[curr+a[curr]]) {
                vis[curr+a[curr]] = 1;
                dis[curr+a[curr]] = dis[curr]+1;
                q.push(curr+a[curr]);
            }
        }
        if(curr-a[curr] >= 1) {
            if(!vis[curr-a[curr]]) {
                vis[curr-a[curr]] = 1;
                dis[curr-a[curr]] = dis[curr]+1;
                q.push(curr-a[curr]);
            }
        }
    }
    cout << dis[N] << endl;
    return 0;
}