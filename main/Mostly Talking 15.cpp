#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef unordered_set<int> u_si;
typedef unordered_map<string, int> u_msi;

int MAX_INT = 2147483647;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int N, M; cin >> N >> M;
    vector<pii> adj1[N+1];
    vector<pii> adj2[N+1];
    for(int i = 0,a,b,k; i < M; i++) {
        cin >> a >> b >> k;
        adj1[a].pb(mp(k,b));
        adj2[b].pb(mp(k,a));
    }
    int dis1[N+1]; fill_n(dis1, N+1, MAX_INT);
    dis1[1] = 0;
    int dis2[N+1]; fill_n(dis2, N+1, MAX_INT);
    dis2[N] = 0;
    bool vis[N+1] = {false};
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(mp(0,1));
    while(!pq.empty()) {
        pii curr = pq.top();
        pq.pop();
        if(vis[curr.se]) continue;
        vis[curr.se] = true;
        for(pii e: adj1[curr.se]) {
            if(curr.fi + e.fi < dis1[e.se]) {
                dis1[e.se] = curr.fi + e.fi;
                pq.push(mp(dis1[e.se], e.se));
            }
        }
    }
    for(int i = 0; i <= N; i++) vis[i] = false;
    pq.push(mp(0,N));
    while(!pq.empty()) {
        pii curr = pq.top();
        pq.pop();
        if(vis[curr.se]) continue;
        vis[curr.se] = true;
        for(pii e: adj2[curr.se]) {
            if(curr.fi + e.fi < dis2[e.se]) {
                dis2[e.se] = curr.fi + e.fi;
                pq.push(mp(dis2[e.se], e.se));
            }
        }
    }
    //for(int i = 1; i <= N; i++) {cout << dis1[i] << " ";} cout << "\n";
    //for(int i = 1; i <= N; i++) {cout << dis2[i] << " ";} cout << "\n";
    int D; cin >> D;
    int ans = dis1[N];
    for(int i = 0,a,b,g; i < D; i++) {
        cin >> a >> b >> g;
        if(dis1[a] != MAX_INT && dis2[b] != MAX_INT) {
            ans = min(ans, dis1[a]+g+dis2[b]);
        }
    }
    if(ans == MAX_INT) cout << -1 << "\n";
    else cout << ans << "\n";
    return 0;
}