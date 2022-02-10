#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int MAX_INT = 2147483647;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, M, B, Q; cin >> N >> M >> B >> Q;
    vector<pii> adj[N+1];
    for(int i = 0,x,y,z; i < M; i++) {
        cin >> x >> y >> z;
        adj[x].push_back(mp(z,y));
        adj[y].push_back(mp(z,x));
    }
    int dist[N+1]; fill_n(dist, N+1, MAX_INT);
    dist[B] = 0;
    bool visited[N+1] = {false};
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(mp(0, B));
    while(!pq.empty()) {
        pii curr = pq.top();
        pq.pop();
        if(visited[curr.second]) continue;
        else visited[curr.second] = true;
        for(pii edge: adj[curr.second]) {
            if(curr.first + edge.first < dist[edge.second]) {
                dist[edge.second] = curr.first + edge.first;
                pq.push(mp(dist[edge.second], edge.second));
            }
        }
    }
    for(int i = 0,A; i < Q; i++) {
        cin >> A;
        if(dist[A] == MAX_INT) cout << -1 << "\n";
        else cout << dist[A] << "\n";
    }
    return 0;
}