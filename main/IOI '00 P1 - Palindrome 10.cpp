#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, double> pid;
typedef pair<double, int> pdi;
typedef pair<pii, int> piipi;
#define MAXN 5000
int dp[2][MAXN+1];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    memset(dp, 0, sizeof(dp));
    int N; cin >> N;
    string str; cin >> str;
    for(int i = 1; i <= N; i++) {
        for(int j = i-1; j > 0; j--) {
            if(str.at(i-1) == str.at(j-1)) {
                dp[i%2][j] = dp[(i-1)%2][j+1];
            } else {
                dp[i%2][j] = min(dp[(i-1)%2][j], dp[i%2][j+1])+1;
            }
        }
    }
    cout << dp[N%2][1] << "\n";
    return 0;
}