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
typedef pair<int, double> pid;
typedef pair<double, int> pdi;
typedef pair<pii, int> piipi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef unordered_set<int> u_si;
typedef unordered_map<string, int> u_msi;

#define MAXNA 490000

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int R, C, K; cin >> R >> C >> K;
    bool safe[R+1][C+1];
    int dp[R+1][C+1];
    for(int i = 0; i <= R; i++) {
        fill_n(safe[i], C+1, true);
        fill_n(dp[i], C+1, 0);
    }
    for(int i = 0,r,c; i < K; i++) {
        cin >> r >> c;
        safe[r][c] = false;
    }
    dp[0][1] = 1;
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            if(safe[i][j]) {
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    cout << dp[R][C] << "\n";
    return 0;
}