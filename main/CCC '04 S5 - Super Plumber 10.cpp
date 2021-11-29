#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef pair<int, pii> pipii;
int val[101][101];
int dp[101][101];//0 = up, 1 = right, 2 = down
int vis[101][101];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int R,C;
    while(true) {
        memset(val, 0, sizeof(val));
        memset(dp, 0, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        cin >> R >> C; string str;
        if(R == 0 && C == 0) break;
        for(int i = 1; i <= R; i++) {
            cin >> str;
            for(int j = 1; j <= C; j++) {
                if(str.at(j-1) > 48 && str.at(j-1) <= 57) val[i][j] = str.at(j-1)-48;
                else if(str.at(j-1) == '*') val[i][j] = -1;
            }
        }
        vis[R][0] = 1;
        for(int j = 1,sum; j <= C; j++) {
            for(int i = R; i >= 1; i--) {
                sum = 0;
                for(int k = i; k >= 1; k--) {
                    if(val[k][j] == -1) break;
                    sum += val[k][j];
                    if(vis[i][j-1]) {
                        dp[k][j] = max(dp[k][j], dp[i][j-1]+sum); vis[k][j] = 1;
                    }
                    if(vis[k][j-1]) {
                        dp[i][j] = max(dp[i][j], dp[k][j-1]+sum); vis[i][j] = 1;
                    }
                }
            }
        }
        /*for(int i = 1; i <= R; i++) {
            for(int j = 1; j <= C; j++) {cout << dp[i][j] << " ";} cout << "\n";
        } cout << "\n";
        for(int i = 1; i <= R; i++) {
            for(int j = 1; j <= C; j++) {cout << vis[i][j] << " ";} cout << "\n";
        }*/
        cout << dp[R][C] << endl;
    }
    return 0;
}