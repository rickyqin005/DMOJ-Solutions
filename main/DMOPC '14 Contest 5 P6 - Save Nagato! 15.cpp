#include <bits/stdc++.h>
using namespace std;
int main() {
	int N; cin >> N;
	vector<int> tree[N+1];
	int dist[N+1][2] = {0};
	bool visited[N+1][3] = {false};
	for(int i = 1; i < N; i++) {
		int u, v; cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	queue<int> line;
	int curr = 0;
	line.push(1); visited[1][0] = true;
	while(!line.empty()) {
		curr = line.front(); line.pop();
		for(int i: tree[curr]) {
			if(visited[i][0]) continue;
			visited[i][0] = true;
			line.push(i);
		}
	}

	line.push(curr); visited[curr][1] = true;
	while(!line.empty()) {
		curr = line.front(); line.pop();
		int currDist = dist[curr][0];
		for(int i: tree[curr]) {
			if(visited[i][1]) continue;
			dist[i][0] = currDist+1;
			visited[i][1] = true;
			line.push(i);
		}
	}

	line.push(curr); visited[curr][2] = true;
	while(!line.empty()) {
		curr = line.front(); line.pop();
		int currDist = dist[curr][1];
		for(int i: tree[curr]) {
			if(visited[i][2]) continue;
			dist[i][1] = currDist+1;
			visited[i][2] = true;
			line.push(i);
		}
	}

	for(int i = 1; i <= N; i++) {
		cout << max(dist[i][0],dist[i][1])+1 << endl;
	}
	return 0;
}