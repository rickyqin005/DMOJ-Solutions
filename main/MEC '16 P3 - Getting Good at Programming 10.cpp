#include<bits/stdc++.h>
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
typedef vector<int> vii;
typedef vector<ll> vll;

#define MAXN 100
#define MAXT 100
#define MAXL 100
int dp[MAXT+1];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    int N, T; cin >> N >> T;
    dp[0] = 0;
    for(int i = 0,L,t,x,currT,currX; i < N; i++) {
        cin >> L;
        int lvl[L][2];
        for(int j = 0; j < L; j++) {
            cin >> lvl[j][0] >> lvl[j][1];
        }
        for(int j = T; j >= 0; j--) {
            if(dp[j] == -1) continue;
            currT = 0; currX = 0;
            for(int k = 0; k < L; k++) {
                currT += lvl[k][0]; currX += lvl[k][1];
                if(j+currT > T) break;
                dp[j+currT] = max(dp[j+currT], dp[j]+currX);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= T; i++) ans = max(ans, dp[i]);
    cout << ans << "\n";
    return 0;
}