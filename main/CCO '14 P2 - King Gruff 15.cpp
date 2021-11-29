#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
bool comp1(vector<int> a, vector<int> b) {
    return a[3] < b[3];
}
bool comp2(pii a, pii b) {
    return a.first < b.first;
}
int MAX_INT = 2147483647;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N,M,A,B; cin >> N >> M >> A >> B;
    vector<vector<int>> adj1[N+1];
    vector<vector<int>> adj2[N+1];
    for(int i = 0,x,y,l,c; i < M; i++) {
        cin >> x >> y >> l >> c;
        vector<int> vect = {l,y,c};//{length, destination, shutdown cost}
        adj1[x].push_back(vect);
        vect = {l,x,c};
        adj2[y].push_back(vect);
    }
    bool visited[N+1] = {false};
    ll dist1[N+1]; fill_n(dist1, N+1, MAX_INT);
    dist1[A] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0,A));
    while(!pq.empty()) {
        pii curr = pq.top();
        pq.pop();
        if(visited[curr.second]) continue;
        visited[curr.second] = true;
        for(vector<int> edge: adj1[curr.second]) {
            if(curr.first+edge[0] < dist1[edge[1]]) {
                dist1[edge[1]] = curr.first + edge[0];
                pq.push(make_pair(dist1[edge[1]], edge[1]));
            }
        }
    }

    for(int i = 0; i <= N; i++) {visited[i] = false;}
    int dist2[N+1]; fill_n(dist2, N+1, MAX_INT);
    dist2[B] = 0;
    pq.push(make_pair(0,B));
    while(!pq.empty()) {
        pii curr = pq.top();
        pq.pop();
        if(visited[curr.second]) continue;
        visited[curr.second] = true;
        for(vector<int> edge: adj2[curr.second]) {
            if(curr.first+edge[0] < dist2[edge[1]]) {
                dist2[edge[1]] = curr.first + edge[0];
                pq.push(make_pair(dist2[edge[1]], edge[1]));
            }
        }
    }
    //for(int i = 1; i <= N; i++) {cout << dist1[i] << " ";} cout << endl;
    //for(int i = 1; i <= N; i++) {cout << dist2[i] << " ";} cout << endl;

    vector<vector<int>> edges;
    for(int i = 1; i <= N; i++) {
        for(int j = 0,val; j < adj1[i].size(); j++) {
            if(dist1[i] == MAX_INT || dist2[adj1[i][j][1]] == MAX_INT) val = MAX_INT;
            else val = dist1[i]+adj1[i][j][0]+dist2[adj1[i][j][1]];
            adj1[i][j].push_back(val);//{length, destination, shutdown cost, shortest path through edge}
            edges.push_back(adj1[i][j]);
        }
    }

    sort(edges.begin(), edges.end(), comp1);
    //for(int i = 0; i < edges.size(); i++) {cout << edges[i][3] << " ";} cout << endl;

    int Q; cin >> Q;
    vector<pii> query;
    for(int i = 0,D; i < Q; i++) {
        cin >> D;
        query.push_back(make_pair(D,i));
    }
    sort(query.begin(), query.end(), comp2);
    int ans[Q];
    int sum = 0, pos = 0;
    for(int i = 0; i < Q; i++) {
        if(pos < M) {
            while(edges[pos][3] <= query[i].first) {
                sum += edges[pos][2];
                pos++;
                if(pos == M) break;
            }
        }
        ans[query[i].second] = sum;
    }
    for(int i = 0; i < Q; i++) {cout << ans[i] << "\n";}
    return 0;
}