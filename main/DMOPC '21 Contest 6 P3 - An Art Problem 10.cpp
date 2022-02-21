#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;
int grid[1501][1501];
int grid2[1501][1501];
int vis[1501][1501];
int dis[1501][1501];
const pii dir[4] = {mp(0,1), mp(0,-1), mp(1,0), mp(-1,0)};
queue<pii> q;
vector<ppiii> cellCol;
bool comp(ppiii a, ppiii b) {return a.s < b.s;}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    memset(grid, 0, sizeof(grid));
    memset(grid2, -1, sizeof(grid2));
    int N,M,K; cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> grid[i][j];
            if(grid[i][j]) cellCol.pb(mp(mp(i,j), grid[i][j]));
        }
    }
    sort(cellCol.begin(), cellCol.end(), comp);
    for(ppiii cell: cellCol) {
        vis[cell.f.f][cell.f.s] = true;
        grid2[cell.f.f][cell.f.s] = cell.s;
        q.push(cell.f);
    }
    q.push(mp(-1, -1));
    int len = 0;
    while(!q.empty()) {
        pii curr = q.front(); q.pop();
        if(curr.f == -1) {
            len++;
            if(len == K) break;
            if(!q.empty()) q.push(mp(-1,-1));
            continue;
        }
        for(int i = 0; i < 4; i++) {
            int newr = curr.f+dir[i].f, newc = curr.s+dir[i].s;
            if(!(newr >= 1 && newr <= N && newc >= 1 && newc <= M)) continue;
            if(vis[newr][newc]) continue;
            vis[newr][newc] = true;
            grid2[newr][newc] = grid2[curr.f][curr.s];
            q.push(mp(newr, newc));
        }
    }
    
    for(int i = 1; i <= N; i++) {
        cout << (grid[i][1] ? grid[i][1] : (grid2[i][1] == -1 ? 0 : grid2[i][1]));
        for(int j = 2; j <= M; j++) cout << " " <<  (grid[i][j] ? grid[i][j] : (grid2[i][j] == -1 ? 0 : grid2[i][j]));
        cout << "\n";
    }
    return 0;
}