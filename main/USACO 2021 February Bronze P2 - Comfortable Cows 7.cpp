#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807
#define MAX_DOUBLE 1e18
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef vector<int> vii;
typedef vector<ll> vll;
#define MAXx 1001
#define MAXy 1001
bool cow[MAXx+2][MAXy+2];
bool good[MAXx+2][MAXy+2];
int cnt = 0;
int adj[5][2] = {{1,0},{-1,0},{0,1},{0,-1},{0,0}};
void check(int x, int y) {
    cow[x][y] = true;
    for(int i = 0,nx,ny,nAdj; i < 5; i++) {
        nx = x+adj[i][0]; ny = y+adj[i][1];
        if(nx == -1 || nx == 1001 || ny == -1 || ny == 1001) continue;
        if(!cow[nx][ny]) continue;
        nAdj = cow[nx+1][ny]+cow[nx-1][ny]+cow[nx][ny+1]+cow[nx][ny-1];
        if(nAdj == 3) {
            if(!good[nx][ny]) {
                cnt++;
                good[nx][ny] = 1;
            }
        } else if(good[nx][ny]) {
            good[nx][ny] = 0;
            cnt--;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    memset(cow, 0, sizeof(cow));
    memset(good, 0, sizeof(good));
    int N; cin >> N;
    for(int i = 0,x,y; i < N; i++) {
        cin >> x >> y;
        check(y,x);
        cout << cnt << "\n";
    }
    return 0;
}