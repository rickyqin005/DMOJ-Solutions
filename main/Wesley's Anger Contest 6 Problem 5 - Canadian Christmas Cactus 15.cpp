#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 222333555557777777
#define BASE 31
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
vector<int> adj[200001];
bool used[200001];
void dfs(int curr, int par) {
    if(adj[curr].size() == 1 && curr != 1) return;
    for(int next: adj[curr]) {
        if(next == par) continue;
        dfs(next, curr);
    }

    int prevChild = -1;
    for(int next: adj[curr]) {
        if(next == par) continue;
        if(used[next]) continue;
        if(prevChild == -1) {
            prevChild = next;
        } else {
            cout << prevChild << " " << next << "\n";
            used[prevChild] = true;
            used[next] = true;
            prevChild = -1;
        }
    }
    if(prevChild != -1 && curr != 1) {
        cout << prevChild << " " << par << "\n";
        used[prevChild] = true;
        used[curr] = true;
    }
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(used, 0, sizeof(used));
    int N; cin >> N;
    for(int i = 1,u,v; i < N; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cout << (N-1)/2 << "\n";
    dfs(1, -1);
    return 0;
}