#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;
char grid[800][800];
int dis1[800][800];
int dis2[800][800];
bool vis[800][800];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dis1, 0x7f, sizeof(dis1));
    memset(dis2, 0x7f, sizeof(dis2));
    memset(vis, 0, sizeof(vis));
    int N,S; cin >> N >> S;
    string str;
    pii A = mp(0,0), B = mp(0,0);
    queue<pii> q;
    for(int i = 0; i < N; i++) {
        cin >> str;
        for(int j = 0; j < N; j++) {
            grid[i][j] = str[j];
            if(grid[i][j] == 'H') {
                dis1[i][j] = 0;
                vis[i][j] = 1;
                q.push(mp(i,j));
            } else if(grid[i][j] == 'M') A = mp(i,j);
            else if(grid[i][j] == 'D') B = mp(i,j);
        }
    }
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int low = 0, high = 0, mid = 0, ans = -1;
    while(!q.empty()) {
        pii curr = q.front(); q.pop();
        for(int i = 0,newR,newC; i < 4; i++) {
            newR = curr.f+dir[i][0]; newC = curr.s+dir[i][1];
            if(!(newR >= 0 && newR < N && newC >= 0 && newC < N)) continue;
            if((grid[newR][newC] == 'G' || grid[newR][newC] == 'M') && !vis[newR][newC]) {
                dis1[newR][newC] = dis1[curr.f][curr.s]+1;
                high = max(high, dis1[newR][newC]);
                vis[newR][newC] = 1;
                q.push(mp(newR,newC));
            }
        }
    }
    while(low < high) {
        mid = (low+high)/2;
        memset(vis, 0, sizeof(vis));
        if(mid < dis1[A.f][A.s]) {
            memset(dis2, 0x7f, sizeof(dis2));
            q.push(A);
            dis2[A.f][A.s] = 0;
            vis[A.f][A.s] = 0;
            while(!q.empty()) {
                pii curr = q.front(); q.pop();
                for(int i = 0,newR,newC; i < 4; i++) {
                    newR = curr.f+dir[i][0]; newC = curr.s+dir[i][1];
                    if(!(newR >= 0 && newR < N && newC >= 0 && newC < N)) continue;
                    if((grid[newR][newC] == 'G' || grid[newR][newC] == 'D') && !vis[newR][newC]) {
                        if(dis1[newR][newC] > mid+(dis2[curr.f][curr.s]+1)/S) {
                            dis2[newR][newC] = dis2[curr.f][curr.s]+1;
                            vis[newR][newC] = 1;
                            q.push(mp(newR,newC));
                        }
                    }
                }
            }
        }
        if(vis[B.f][B.s]) {
            low = mid+1;
            ans = max(ans, mid);
        } else high = mid;
    }
    cout << ans << "\n";
    return 0;
}