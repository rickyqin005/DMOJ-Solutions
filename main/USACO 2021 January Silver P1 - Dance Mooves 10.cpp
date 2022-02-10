#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, K; cin >> N >> K;
    unordered_set<int> moves[N+1];
    int cow[N+1];
    for(int i = 1; i <= N; i++) {
        cow[i] = i;
        moves[i].insert(i);
    }
    for(int i = 0,a,b,temp; i < K; i++) {
        cin >> a >> b;
        moves[cow[a]].insert(b);
        moves[cow[b]].insert(a);
        temp = cow[a];
        cow[a] = cow[b];
        cow[b] = temp;
    }
    int ans[N+1] = {0};
    bool visited[N+1] = {false};
    for(int i = 1,curr; i <= N; i++) {
        if(visited[i]) continue;
        curr = cow[i];
        queue<int> q;
        q.push(curr);
        while(cow[curr] != cow[i]) {
            curr = cow[curr];
            q.push(curr);
            moves[cow[i]].insert(moves[curr].begin(), moves[curr].end());
        }
        while(!q.empty()) {
            curr = q.front();
            q.pop();
            visited[curr] = true;
            ans[curr] = moves[cow[i]].size();
        }
    }
    for(int i = 1; i <= N; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}