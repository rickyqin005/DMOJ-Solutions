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

#define MAXA 1000
int dp[MAXA+1][MAXA+1];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    memset(dp, 0, sizeof(dp));
    int D, I, R; cin >> D >> I >> R;
    string A, B; cin >> A >> B;
    dp[0][0] = 0;
    for(int i = 1; i <= A.length(); i++) {dp[i][0] = i*D;}
    for(int i = 1; i <= B.length(); i++) {dp[0][i] = i*I;}
    for(int i = 1; i <= A.length(); i++) {
        for(int j = 1; j <= B.length(); j++) {
            if(A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min(min(dp[i][j-1]+I, dp[i-1][j-1]+R), dp[i-1][j]+D);
            }
        }
    }
    cout << dp[A.length()][B.length()] << "\n";
    return 0;
}