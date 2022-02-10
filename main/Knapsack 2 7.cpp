#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N,W; cin >> N >> W;
    int NUMROWS = 1000*N;
    int MAXINT = 2000000000;
    int dp[NUMROWS+1]; fill_n(dp, NUMROWS+1, MAXINT);
    for(int i = 0,w,v; i < N; i++) {
        cin >> w >> v;
        for(int j = NUMROWS-v; j > 0; j--) {
            if(dp[j] != MAXINT) {
                if(dp[j]+w <= W) {
                    dp[j+v] = min(dp[j+v], dp[j]+w);
                }
            }
        }
        if(w <= W) {
            dp[v] = min(dp[v], w);
        }
        //for(int j = 0; j <= 14; j++) {cout << dp[j] << " ";}
        //cout << "\n";
    }

    int ans = 0;
    for(int i = NUMROWS; i > 0; i--) {
        if(dp[i] != MAXINT) {
            ans = i;
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}