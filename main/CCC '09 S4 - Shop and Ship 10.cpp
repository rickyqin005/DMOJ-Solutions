#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, T; cin >> N >> T;
    vector<pii> adj[N+1];//pair<cost, y>
    for(int i = 0,x,y,c; i < T; i++) {
        cin >> x >> y >> c;
        adj[x].push_back(make_pair(c,y));
        adj[y].push_back(make_pair(c,x));
    }
    int pencil[N+1];
    fill_n(pencil, N+1, -1);
    int K; cin >> K;
    for(int i = 0,z,p; i < K; i++) {
        cin >> z >> p;
        pencil[z] = p;
    }
    int D; cin >> D;
    bool visited[N+1] = {false};
    int dist[N+1];
    fill_n(dist, N+1, 2000000000);
    dist[D] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, D));
    while(!pq.empty()) {
        pii curr = pq.top();
        pq.pop();
        if(visited[curr.second]) continue;
        visited[curr.second] = true;
        for(pii edge: adj[curr.second]) {
            if(curr.first+edge.first < dist[edge.second]) {
                dist[edge.second] = curr.first + edge.first;
                pq.push(make_pair(dist[edge.second], edge.second));
            }
        }
    }
    int ans = 2000000000;
    for(int i = 1; i <= N; i++) {
        if(pencil[i] != -1) {
            if(dist[i] + pencil[i] < ans) {
                ans = dist[i]+pencil[i];
            }
        }
    }
    cout << ans << "\n";
    return 0;
}