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
typedef tuple<int,int,int> tiii;
int R,C;
ll arr[503][503];
pair<int, ll> ans[502][502];
pii dir[4] = {mp(1,0), mp(-1,0), mp(0,1), mp(0,-1)};
void dfs(int r, int c) {
    ans[r][c] = mp(1,arr[r][c]);
    for(int i = 0,newr,newc; i < 4; i++) {
        newr = r+dir[i].f; newc = c+dir[i].s;
        if(!(newr >= 1 && newr <= R && newc >= 1 && newc <= C)) continue;
        if(arr[newr][newc] <= arr[r][c]) continue;
        if(ans[newr][newc] == mp(0,0LL)) dfs(newr, newc);
        if(ans[newr][newc].f+1 > ans[r][c].f) {
            ans[r][c] = mp(ans[newr][newc].f+1, ans[newr][newc].s+arr[r][c]);
        } else if(ans[newr][newc].f+1 == ans[r][c].f) ans[r][c].s = max(ans[r][c].s, ans[newr][newc].s+arr[r][c]);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(arr, 0, sizeof(arr));
    memset(ans, 0, sizeof(ans));
    int M; cin >> C >> R >> M;
    for(int i = 1,r,c,w,h,n; i <= M; i++) {
        cin >> c >> r >> w >> h >> n;
        arr[r][c] += n;
        arr[r][c+w] += -n*(w+1);
        arr[r][c+w+1] += n*w;
        arr[r+h][c] += -n*(h+1);
        arr[r+h][c+w] += n*w*h + n*(w+1) + n*h;
        arr[r+h][c+w+1] += -n*w*h - n*w;
        arr[r+h+1][c] += n*h;
        arr[r+h+1][c+w] += -n*w*h - n*h;
        arr[r+h+1][c+w+1] += n*w*h;
    }
    int A,B; cin >> B >> A;
    for(int j = 1; j <= C; j++) {
        for(int i = 1; i <= R; i++) arr[i][j] += arr[i-1][j];
    }
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) arr[i][j] += arr[i][j-1];
    }
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) arr[i][j] += arr[i][j-1];
    }
    for(int j = 1; j <= C; j++) {
        for(int i = 1; i <= R; i++) arr[i][j] += arr[i-1][j];
    }
    dfs(A, B);
    cout << ans[A][B].s%MOD << "\n";
    return 0;
}