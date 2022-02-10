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
string str;
char grid[1001][1001];
int ans[1001][1001];
bool vis[1001][1001];
struct Comp {
public: bool operator()(pii a, pii b) {return ans[a.f][a.s] > ans[b.f][b.s];}
};
priority_queue<pii, vector<pii>, Comp> pq;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(ans, 0, sizeof(ans));
    memset(vis, 0, sizeof(vis));
    int R, C; cin >> R >> C;
    for(int i = 1; i <= R; i++) {
        cin >> str;
        for(int j = 1; j <= C; j++) {
            grid[i][j] = str[j-1];
        }
    }
    if(grid[1][1] == 'C') ans[1][1] = 1;
    vis[1][1] = true;
    pq.push(mp(1,1));
    const pii dir[4] = {mp(1,0), mp(-1,0), mp(0,1), mp(0,-1)};
    while(!pq.empty()) {
        pii curr = pq.top(); pq.pop();
        for(int d = 0; d < 4; d++) {
            int newr = curr.f+dir[d].f, newc = curr.s+dir[d].s;
            if(!(newr >= 1 && newr <= R && newc >= 1 && newc <= C)) continue;
            if(vis[newr][newc]) continue;
            vis[newr][newc] = true;
            ans[newr][newc] = ans[curr.f][curr.s] + (grid[newr][newc]=='C');
            pq.push(mp(newr, newc));
        }
    }
    cout << ans[R][C] << "\n";
    return 0;
}