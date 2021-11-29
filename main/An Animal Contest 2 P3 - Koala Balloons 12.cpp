#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef pair<int, pii> pipii;
int R,C;
bool grid[1502][1502];
bool obr[1502][1502];
bool obc[1502][1502];
bool vis[1502][1502];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool solve(int b) {
    memset(obr, 0, sizeof(obr));
    memset(obc, 0, sizeof(obc));
    memset(vis, 0, sizeof(vis));

    for(int i = 1; i <= b; i++) {
        for(int j = 1; j <= b; j++) if(grid[i][j]) return 0;
    }

    for(int i = 1,curr; i <= R; i++) {
        curr = 0;
        for(int j = C; j >= 1; j--) {
            curr += grid[i][j];
            if(j+b <= C) curr -= grid[i][j+b];
            obr[i][j] = (curr > 0);
        }
    }
    for(int j = 1,curr; j <= C; j++) {
        curr = 0;
        for(int i = R; i >= 1; i--) {
            curr += grid[i][j];
            if(i+b <= R) curr -= grid[i+b][j];
            obc[i][j] = (curr > 0);
        }
    }
    /*cout << b << ": " << "\n";
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {cout << obr[i][j] << " ";} cout << "\n";
    } cout << "\n";
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {cout << obc[i][j] << " ";} cout << "\n";
    } cout << "\n\n\n";*/

    queue<pii> q;
    q.push(mp(1,1));
    vis[1][1] = 1;
    while(!q.empty()) {
        pii curr = q.front(); q.pop();
        if(curr.f+b-1 == R && curr.s+b-1 == C) return 1;

        if(curr.f+b <= R) {
            if(!obr[curr.f+b][curr.s] && !vis[curr.f+1][curr.s]) {
                q.push(mp(curr.f+1,curr.s));
                vis[curr.f+1][curr.s] = 1;
            }
        }
        if(curr.s+b <= C) {
            if(!obc[curr.f][curr.s+b] && !vis[curr.f][curr.s+1]) {
                q.push(mp(curr.f,curr.s+1));
                vis[curr.f][curr.s+1] = 1;
            }
        }
        if(curr.f-1 >= 1) {
            if(!obr[curr.f-1][curr.s] && !vis[curr.f-1][curr.s]) {
                q.push(mp(curr.f-1,curr.s));
                vis[curr.f-1][curr.s] = 1;
            }
        }
        if(curr.s-1 >= 1) {
            if(!obc[curr.f][curr.s-1] && !vis[curr.f][curr.s-1]) {
                q.push(mp(curr.f,curr.s-1));
                vis[curr.f][curr.s-1] = 1;
            }
        }
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(grid, 0, sizeof(grid));
    cin >> R >> C; string str;
    for(int i = 1; i <= R; i++) {
        cin >> str;
        for(int j = 1; j <= C; j++) grid[i][j] = (str[j-1]=='X');
    }
    int ans = 0;
    int low = 0, high = min(R,C)+1, mid;
    while(low < high) {
        mid = (low+high)/2;
        if(solve(mid)) {
            ans = max(ans,mid);
            low = mid+1;
        } else {
            high = mid;
        }
    }
    cout << ans << "\n";
    return 0;
}