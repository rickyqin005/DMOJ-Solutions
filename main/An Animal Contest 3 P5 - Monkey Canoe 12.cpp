#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int R,C;
bool grid[2001][2001];
int component[2001][2001];
vector<int> topRow(1);
bool vis[2001][2001];
queue<pii> q;
struct Edge {
    int u,v,l;
    Edge(int U, int V, int L){u = U; v = V; l = L;}
};
bool comp(Edge a, Edge b) {return a.l > b.l;}
vector<Edge> edge;
struct disjoint_set {
private: vector<int> parent, weight;
public:
    int N;
    void set_range(int n) {N = n;}
    disjoint_set(int n) {
        set_range(n);
        parent = vector<int>(N+1);
        weight = vector<int>(N+1);
        for(int i = 1; i <= N; i++) parent[i] = i;
    }
    int get_parent(int a) {
        if(parent[a] != a) parent[a] = get_parent(parent[a]);
        return parent[a];
    }
    int get_top(int a) {
        if(parent[a] != a) return get_top(parent[a]);
        return topRow[a];
    }
    bool join(int a, int b) {
        a = get_parent(a); b = get_parent(b);
        if(a != b) {
            if(weight[a] > weight[b]) {
                parent[b] = a; weight[a] += weight[b]+1; topRow[a] = min(topRow[a], topRow[b]);
            } else {
                parent[a] = b; weight[b] += weight[a]+1; topRow[b] = min(topRow[b], topRow[a]);
            }
            return true;
        }
        return false;
    }
    void print(ostream &out = cout) {
        for(int i = 1; i <= N; i++) {out << parent[i] << " ";} out << "\n";
        for(int i = 1; i <= N; i++) {out << weight[i] << " ";} out << "\n";
        for(int i = 1; i <= N; i++) {out << topRow[i] << " ";} out << "\n";
    }
};
disjoint_set dsu(2000000);
int ans[2001];
pii dir[] = {mp(1,0), mp(-1,0), mp(0,1), mp(0,-1)};
void bfs(int r, int c, int n) {
    vis[r][c] = 1;
    component[r][c] = n;
    q.push(mp(r,c));
    while(!q.empty()) {
        int cr = q.front().f, cc = q.front().s; q.pop();
        for(int i = 0,newr,newc; i < 4; i++) {
            newr = cr+dir[i].f; newc = cc+dir[i].s;
            if(!(r >= 1 && r <= R && c >= 1 && c <= C)) continue;
            if(vis[newr][newc]) continue;
            if(!grid[newr][newc]) continue;
            vis[newr][newc] = 1;
            component[newr][newc] = n;
            q.push(mp(newr,newc));
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> R >> C; string str;
    for(int i = 1; i <= R; i++) {
        cin >> str;
        for(int j = 1; j <= C; j++) grid[i][j] = (str[j-1] == '#');
    }
    memset(component, -1, sizeof(component));
    memset(vis, 0, sizeof(vis));
    for(int i = 1,cnt = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            if(!vis[i][j] && grid[i][j]) {
                topRow.pb(i);
                bfs(i,j,cnt);
                cnt++;
            }
        }
    }
    dsu.set_range(topRow.size()-1);
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j < C;) {
            if(grid[i][j] && !grid[i][j+1]) {
                int start = j; j++;
                for(int len = 1; j <= C; j++,len++) {
                    if(grid[i][j]) {
                        if(component[i][start] != component[i][j]) edge.pb(Edge(component[i][start], component[i][j], len-1));
                        break;
                    }
                }
            } else j++;
        }
    }
    for(int j = 1; j <= C; j++) {
        for(int i = 1; i < R;) {
            if(grid[i][j] && !grid[i+1][j]) {
                int start = i; i++;
                for(int len = 1; i <= R; i++,len++) {
                    if(grid[i][j]) {
                        if(component[start][j] != component[i][j]) edge.pb(Edge(component[start][j], component[i][j], len-1));
                        break;
                    }
                }
            } else i++;
        }
    }
    sort(edge.begin(), edge.end(), comp);
    memset(ans, -1, sizeof(ans));
    for(int j = 1; j <= C; j++) {
        if(grid[R][j]) {
            if(topRow[component[R][j]] == 1) ans[j] = 0;
        }
    }
    for(int i = 0; i < edge.size(); i++) {
        dsu.join(edge[i].u, edge[i].v);
        if(i == edge.size()-1 || (i != edge.size()-1 && edge[i].l != edge[i+1].l)) {
            for(int j = 1; j <= C; j++) {
                if(grid[R][j] && ans[j] == -1) {
                    if(dsu.get_top(component[R][j]) == 1) ans[j] = edge[i].l;
                }
            }
        }
    }
    for(int j = 1; j <= C; j++) {
        cout << ans[j];
        if(j != C) cout << " ";
    } cout << "\n";
    return 0;
}