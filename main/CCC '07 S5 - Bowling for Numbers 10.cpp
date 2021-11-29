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

#define MAXN 30000
int arr[MAXN+1];
int val[MAXN+1];
int dp[MAXN+1][2];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    for(int i = 0,n,k,w; i < t; i++) {
        for(int j = 0; j <= MAXN; j++) {
            arr[j] = 0;
            val[j] = 0;
            dp[j][0] = 0;
            dp[j][1] = 0;
        }
        cin >> n >> k >> w;
        for(int j = 1; j <= n; j++) {
            cin >> arr[j];
            arr[j] += arr[j-1];
        }
        for(int j = 1; j <= n; j++) {
            val[j] = arr[j] - arr[max(0, j-w)];
        }
        for(int j = 1; j <= k; j++) {
            for(int pos = 1; pos <= n; pos++) {
                dp[pos][j%2] = max(dp[pos-1][j%2], dp[max(0,pos-w)][!(j%2)]+val[pos]);
            }
        }
        cout << dp[n][k%2] << "\n";
        //for(int j = 1; j <= n; j++) {cout << dp[j][0] << " ";} cout << "\n";
        //for(int j = 1; j <= n; j++) {cout << dp[j][1] << " ";} cout << "\n";
    }
    return 0;
}