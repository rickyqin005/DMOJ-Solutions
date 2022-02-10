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
bool dp[31][31][31][31];
bool vis[31][31][31][31];
bool solve(int a, int b, int c, int d) {
    if(vis[a][b][c][d]) return dp[a][b][c][d];
    bool win = 0;
    //AABDD
    if(a >= 2 && b >= 1 && d >= 2) {
        win = win||!solve(a-2, b-1, c, d-2);
    }
    //ABCD
    if(a >= 1 && b >= 1 && c >= 1 && d >= 1) {
        win = win||!solve(a-1, b-1, c-1, d-1);
    }
    //CCD
    if(c >= 2 && d >= 1) {
        win = win||!solve(a, b, c-2, d-1);
    }
    //BBB
    if(b >= 3) {
        win = win||!solve(a, b-3, c, d);
    }
    //AD
    if(a >= 1 && d >= 1) {
        win = win||!solve(a-1, b, c, d-1);
    }
    dp[a][b][c][d] = win;
    vis[a][b][c][d] = 1;
    return win;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    int N; cin >> N;
    for(int i = 1,A,B,C,D; i <= N; i++) {
        cin >> A >> B >> C >> D;
        cout << (solve(A,B,C,D)?"Patrick":"Roland") << "\n";
    }
    return 0;
}