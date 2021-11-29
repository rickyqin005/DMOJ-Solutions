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

#define MAXM 20
#define MAXQ 100
int dp[MAXQ+1][MAXM+1];
int slow[MAXQ+1][MAXM+1];
string name[MAXQ+1];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    memset(dp, 0x7F, sizeof(dp));
    memset(slow, 0x7F, sizeof(slow));
    dp[0][0] = 0;
    slow[0][0] = 0;
    int M, Q; cin >> M >> Q;
    for(int i = 1,t,minCol; i <= Q; i++) {
        cin >> name[i];
        cin >> t;
        minCol = min(dp[i-1][0], dp[i-1][M]);
        for(int j = 2; j <= M; j++) {
            dp[i][j] = dp[i-1][j-1];
            slow[i][j] = max(slow[i-1][j-1], t);
            if(slow[i][j] > slow[i-1][j-1]) {
                dp[i][j] += slow[i][j]-slow[i-1][j-1];
            }
            minCol = min(minCol, dp[i-1][j-1]);
        }

        dp[i][1] = minCol+t;
        slow[i][1] = t;
    }
    int ans = INT_MAX;
    for(int i = 0; i <= M; i++) {ans = min(ans, dp[Q][i]);}
    cout << "Total Time: " << ans << "\n";
    int i = Q,minNum, minIdx;
    vector<int> group;
    while(i > 0) {
        minNum = minIdx = INT_MAX;
        for(int j = 1; j <= M; j++) {
            if(dp[i][j] < minNum) {
                minNum = dp[i][j];
                minIdx = j;
            }
        }
        group.pb(minIdx);
        i -= minIdx;
    }
    int sum = 0;
    for(int i = group.size()-1; i >= 0; i--) {
        for(int j = 0; j < group[i]; j++) {
            cout << name[sum+j+1] << " ";
        }
        cout << "\n";
        sum += group[i];
    }
    return 0;
}