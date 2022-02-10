#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
int arr[1000001];
int sum = 0;
int ansNode = 0;
int ansSum = INT_MAX;
vector<int> adj[1000001];
int dfs(int curr, int prev) {
    int currAns = 0;
    int subSum = 0;
    for(int next: adj[curr]) {
        if(next == prev) continue;
        int res = dfs(next, curr);
        currAns = max(currAns, res);
        subSum += res;
    }
    subSum += arr[curr];
    currAns = max(currAns, sum-subSum);
    if(currAns < ansSum) {
        ansSum = currAns;
        ansNode = curr;
    }
    return subSum;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    for(int i = 1,u,v; i < N; i++) {
        cin >> u >> v; u++; v++;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, -1);
    cout << ansNode-1 << "\n";
    return 0;
}