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
int arr[100001];
vector<int> adj[100001];
int indeg[100001];
int minTime[100001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(indeg, 0, sizeof(indeg));
    memset(minTime, 0, sizeof(minTime));
    int N; cin >> N;
    for(int i = 1,r; i <= N; i++) {
        cin >> arr[i];
        cin >> indeg[i];
        for(int j = 1,u; j <= indeg[i]; j++) {
            cin >> u;
            adj[u].pb(i);
        }
    }
    
    queue<int> q;
    for(int i = 1; i <= N; i++) {
        if(indeg[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        minTime[curr] += arr[curr];
        for(int next: adj[curr]) {
            minTime[next] = max(minTime[next], minTime[curr]);
            indeg[next]--;
            if(indeg[next] == 0) q.push(next);
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; i++) ans = max(ans, minTime[i]);
    cout << ans << "\n";
    return 0;
}