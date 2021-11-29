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
    int N; cin >> N;
    int dp[N][N];
    for(int i = 0; i < N; i++) fill_n(dp[i], N, 0);
    string str;
    for(int i = 0; i < N; i++) {
        cin >> str;
        for(int j = 0; j < N; j++) {
            dp[i][j] = str.at(j)=='#'?1:0;
        }
    }

    for(int i = N-2; i >= 0; i--) {
        for(int j = 1; j < N-1; j++) {
            if(dp[i][j] == 1) dp[i][j] = max(1,min(dp[i+1][j-1], min(dp[i+1][j], dp[i+1][j+1]))+1);
        }
    }
    /*for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) cout << dp[i][j] << " ";
        cout << "\n";
    }*/
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            ans += dp[i][j];
        }
    }
    cout << ans << "\n";
    return 0;
}