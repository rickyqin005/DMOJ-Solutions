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
vector<int> adj[27];
int disc[27];
int low[27];
bool vis[27];
int discTime = 0;
int ans = 0;
void dfs(int curr, int par) {
    vis[curr] = true;
    disc[curr] = low[curr] = discTime++;
    for(int next: adj[curr]) {
        if(next == par) continue;
        if(vis[next]) low[curr] = min(low[curr], disc[next]);
        else {
            dfs(next, curr);
            low[curr] = min(low[curr], low[next]);
            if(low[next] > disc[curr]) {
                cout << (char)(curr-1+'A') << (char)(next-1+'A') << "\n";
                ans++;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(vis, 0, sizeof(vis));
    int start;
    while(true) {
        string str; cin >> str;
        if(str == "**") break;
        start = (str[0]-'A'+1);
        adj[str[0]-'A'+1].pb(str[1]-'A'+1);
        adj[str[1]-'A'+1].pb(str[0]-'A'+1);
    }
    dfs(start, -1);
    cout << "There are " << ans << " disconnecting roads." << "\n";
    return 0;
}