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
char grid[201][201];
string str;
pii locClass[5];
pii loc[257];
queue<pii> q;
bool vis[201][201];
int dis[201][201];
const pii dir[4] = {mp(0, 1), mp(0, -1), mp(1, 0), mp(-1,0)};
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(loc, 0, sizeof(loc));
    int R,C; cin >> R >> C;
    for(int i = 1; i <= R; i++) {
        cin >> str;
        for(int j = 1; j <= C; j++) {
            grid[i][j] = str[j-1];
            if(grid[i][j] >= '0' && grid[i][j] <= '4') {
                locClass[grid[i][j]-'0'] = mp(i,j);
            }
            if(grid[i][j] >= 'A' && grid[i][j] <= 'Z') {
                loc[grid[i][j]] = mp(i,j);
            }
            if(grid[i][j] >= 'a' && grid[i][j] <= 'z') {
                loc[grid[i][j]] = mp(i,j);
            } 
        }
    }
    //for(int i = 'A'; i <= 'z'; i++) {cout << loc[i].f << " " << loc[i].s << "\n";}
    int ans = 0;
    for(int i = 1; i <= 4; i++) {
        memset(vis, 0, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        q.push(locClass[i-1]);
        vis[locClass[i-1].f][locClass[i-1].s] = true;
        dis[locClass[i-1].f][locClass[i-1].s] = 0;
        while(!q.empty()) {
            pii curr = q.front(); q.pop();
            for(int j = 0; j < 4; j++) {
                int newr = curr.f+dir[j].f, newc = curr.s+dir[j].s;
                if(!(newr >= 1 && newr <= R && newc >= 1 && newc <= C)) continue;
                if(grid[newr][newc] == '#') continue;
                if(grid[newr][newc] >= 'a' && grid[newr][newc] <= 'z') continue;
                if(grid[newr][newc] >= 'A' && grid[newr][newc] <= 'Z') {
                    int oldnewr = newr, oldnewc = newc;
                    newr = loc['a'+(grid[oldnewr][oldnewc]-'A')].f;
                    newc = loc['a'+(grid[oldnewr][oldnewc]-'A')].s;
                }
                if(!(newr >= 1 && newr <= R && newc >= 1 && newc <= C)) continue;
                if(vis[newr][newc]) continue;
                vis[newr][newc] = true;
                dis[newr][newc] = dis[curr.f][curr.s]+1;
                q.push(mp(newr, newc));
            }
        }
        /*for(int j = 1; j <= R; j++) {
            for(int k = 1; k <= C; k++) {cout << dis[j][k] << " ";}
            cout << "\n";
        }cout << "\n";*/
        if(dis[locClass[i].f][locClass[i].s] == -1) {cout << -1 << "\n"; return 0;}
        ans += dis[locClass[i].f][locClass[i].s];
    }
    cout << ans << "\n";
    return 0;
}