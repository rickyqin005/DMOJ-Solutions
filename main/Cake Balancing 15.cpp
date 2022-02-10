#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
int L,R,W;
int arrL[10];
int arrR[10];
int dp[1<<20][2];
int diff[1<<20];//right-left
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp, 0x7f, sizeof(dp));
    cin >> L >> R >> W;
    for(int i = 0; i < L; i++) cin >> arrL[i];
    for(int i = 0; i < R; i++) cin >> arrR[i];
    diff[0] = 0;
    for(int i = 0; i < (1<<(L+R))-1; i++) {
        for(int j = 0; j < L; j++) {
            if(i&(1<<j)) continue;
            diff[i|(1<<j)] = diff[i]-arrL[j];
        }
        for(int j = 0; j < R; j++) {
            if(i&(1<<(L+j))) continue;
            diff[i|(1<<(L+j))] = diff[i]+arrR[j];
        }
    }
    //for(int i = 0; i < (1<<(L+R)); i++) cout << bitset<20>(i) << ": " << diff[i] << "\n";
    dp[0][0] = dp[0][1] = 1;
    for(int i = 0; i < (1<<(L+R))-1; i++) {
        for(int j = 0; j < L; j++) {
            int newi = i|(1<<j);
            if(newi == i) continue;
            if(abs(diff[newi]) > W) continue;
            dp[newi][0] = min(dp[newi][0], min(dp[i][0], dp[i][1]+1));
        }
        for(int j = 0; j < R; j++) {
            int newi = i|(1<<(L+j));
            if(newi == i) continue;
            if(abs(diff[newi]) > W) continue;
            dp[newi][1] = min(dp[newi][1], min(dp[i][1], dp[i][0]+1));
        }
    }
    //for(int i = 0; i < (1<<(L+R)); i++) cout << bitset<20>(i) << ": " << dp[i][0] << " " << dp[i][1] << "\n";
    cout << min(dp[(1<<(L+R))-1][0], dp[(1<<(L+R))-1][1]) << "\n";
    return 0;
}