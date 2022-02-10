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
//0 = guarantee lose, 1 = guarantee win
int dp[3][301][3][301];

int solve(int h1, int w1, int h2, int w2) {
    if(dp[h1][w1][h2][w2] != -1) return dp[h1][w1][h2][w2];
    if(dp[h2][w2][h1][w1] != -1) return dp[h2][w2][h1][w1];
    if(w1 == 1 && w2 == 1 && h1 == 1 && h2 == 1) {
        dp[h1][w1][h2][w2] = 0;
        dp[h2][w2][h1][w1] = 0; return 0;
    }

    for(int i = w1-1; i > 0 && i >= w1-10; i--) {
        if(!solve(h1,i,h2,w2)) {
            dp[h1][w1][h2][w2] = 1;
            dp[h2][w2][h1][w1] = 1; return 1;
        }
    }

    for(int i = w2-1; i > 0 && i >= w2-10; i--) {
        if(!solve(h1,w1,h2,i)) {
            dp[h1][w1][h2][w2] = 1;
            dp[h2][w2][h1][w1] = 1; return 1;
        }
    }

    for(int i = 1; i < w1; i++) {
        if(!solve(h1,i,h1,w1-i)) {
            dp[h1][w1][h2][w2] = 1;
            dp[h2][w2][h1][w1] = 1; return 1;
        }
    }

    for(int i = 1; i < w2; i++) {
        if(!solve(h2,i,h2,w2-i)) {
            dp[h1][w1][h2][w2] = 1;
            dp[h2][w2][h1][w1] = 1; return 1;
        }
    }

    if(h1 == 2) {
        if(!solve(1,w1,1,w1)) {
            dp[h1][w1][h2][w2] = 1;
            dp[h2][w2][h1][w1] = 1; return 1;
        }
        if(!solve(1,w1,h2,w2)) {
            dp[h1][w1][h2][w2] = 1;
            dp[h2][w2][h1][w1] = 1; return 1;
        }
    }

    if(h2 == 2) {
        if(!solve(1,w2,1,w2)) {
            dp[h1][w1][h2][w2] = 1;
            dp[h2][w2][h1][w1] = 1; return 1;
        }
        if(!solve(1,w2,h1,w1)) {
            dp[h1][w1][h2][w2] = 1;
            dp[h2][w2][h1][w1] = 1; return 1;
        }
    }

    dp[h1][w1][h2][w2] = 0;
    dp[h2][w2][h1][w1] = 0; return 0;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp, -1, sizeof(dp));
    int h1,w1,h2,w2; cin >> h1 >> w1 >> h2 >> w2;
    int len = w1+w2;
    if(solve(h1,w1,h2,w2)) cout << "W\n";
    else cout << "L\n";
/*
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 5; j++) {cout << dp[i][j] << " ";} cout << "\n";
    }*/
    return 0;
}