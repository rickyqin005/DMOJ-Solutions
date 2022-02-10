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

#define MAXH 5000
ll dp[2][MAXH+1];
bool vis[MAXH+1];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int N, H; cin >> N >> H;
    ll ans; int idx1, idx2;
    for(int i = 0,g,h,q,t; i < N; i++) {
        cin >> g >> h >> q >> t;
        idx1 = i%2; idx2 = (i+1)%2;
        memset(dp[idx1], 0, sizeof(dp[idx1]));
	    memset(vis, 0, sizeof(vis));
		for(int j = 0; j <= H; j++) {
			if (j >= h) {
				dp[idx1][j] = max(dp[idx1][j], dp[idx2][j-h]+g);
				vis[j] = true;
			}
			if (j >= t && vis[j-t]) {
				dp[idx1][j] = max(dp[idx1][j], dp[idx1][j-t]+q);
				vis[j] = true;
			}
		}
		for(int j = 0; j <= H; j++) dp[idx1][j] = max(dp[idx1][j], dp[idx2][j]);
	}
	for(int i = 0; i <= H; i++) ans = max(ans, dp[(N-1)%2][i]);
	cout << ans << "\n";
    return 0;
}