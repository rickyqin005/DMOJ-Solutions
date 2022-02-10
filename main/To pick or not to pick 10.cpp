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

#define MAXa 100000
int dp[MAXa+1];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    memset(dp, 0, sizeof(dp));
    int N; cin >> N;
    for(int i = 0,n; i < N; i++) {
        cin >> n;
        dp[n] += n;
    }
    int currMax = dp[1];
    for(int i = 3; i <= MAXa; i++) {
        dp[i] += currMax;
        currMax = max(currMax, dp[i-1]);
    }
    int ans = 0;
    for(int i = 1; i <= MAXa; i++) {ans = max(ans, dp[i]);}
    cout << ans << "\n";
    return 0;
}