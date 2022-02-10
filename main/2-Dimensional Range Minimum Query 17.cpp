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
int tbl[100][1000][1000];
void init(vector<vector<int>> arr) {
    int N = arr.size();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) tbl[0][i][j] = arr[i][j];
    }
    for(int k = 10,pk = 2; pk <= N; k += 10,pk <<= 1) {
        for(int j = 0; j < N; j++) {
            for(int i = N-pk; i >= 0; i--) tbl[k][i][j] = min(tbl[k-10][i][j], tbl[k-10][i+(pk>>1)][j]);
        }
    }
    for(int k = 0,pk = 1; pk <= N; k += 10,pk <<= 1) {
        for(int l = 1,pl = 2; pl <= N; l++,pl <<= 1) {
            for(int i = N-pk; i >= 0; i--) {
                for(int j = N-pl; j >= 0; j--) tbl[k+l][i][j] = min(tbl[k+l-1][i][j], tbl[k+l-1][i][j+(pl>>1)]);
            }
        }
    }
}
int query(int a, int b, int c, int d) {
    int pi = 31-__builtin_clz(b-a+1), pj = 31-__builtin_clz(d-c+1);
    return min(min(min(
            tbl[pi*10+pj][a][c],
            tbl[pi*10+pj][a][d-(1<<pj)+1]),
            tbl[pi*10+pj][b-(1<<pi)+1][c]),
            tbl[pi*10+pj][b-(1<<pi)+1][d-(1<<pj)+1]);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    return 0;
}