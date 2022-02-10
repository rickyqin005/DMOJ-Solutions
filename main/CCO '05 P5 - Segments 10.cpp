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
int dp[2][20001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp, 0, sizeof(dp));
    int N; cin >> N;
    int l,r,pl,pr; cin >> l >> r;
    dp[0][1] = r-1+(r-l);
    dp[1][1] = r-1;
    pl = l; pr = r;
    for(int i = 2; i <= N; i++) {
        cin >> l >> r;
        dp[0][i] = min(dp[0][i-1]+abs(pl-r), dp[1][i-1]+abs(pr-r))+(r-l)+1;
        dp[1][i] = min(dp[0][i-1]+abs(pl-l), dp[1][i-1]+abs(pr-l))+(r-l)+1;

        pl = l; pr = r;
    }
    cout << min(dp[0][N]+(N-pl), dp[1][N]+(N-pr)) << "\n";
    return 0;
}