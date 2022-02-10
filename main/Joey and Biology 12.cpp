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

#define MAXN 1000
int dp[MAXN+1][MAXN+1];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    memset(dp, 0x7F, sizeof(dp));
    int N, M; cin >> N >> M;
    string A, B; cin >> A >> B;
    dp[0][0] = 0;
    for(int i = 1; i <= N; i++) {dp[i][0] = ceil(i/3.0);}
    for(int i = 1; i <= M; i++) {dp[0][i] = ceil(i/3.0);}

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(A[i-1] == B[j-1]) {
                if(i > 1 && j > 1) {
                    if(A[i-2] == B[j-2]) {
                        if(i > 2 && j > 2) {
                            if(A[i-3] == B[j-3]) {
                                dp[i][j] = dp[i-3][j-3];
                            }
                        }
                        dp[i][j] = min(dp[i][j], dp[i-2][j-2]);
                    }
                }
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);

            } else {
                dp[i][j] = min(min(dp[i][j-1]+1, dp[i-1][j-1]+1), dp[i-1][j]+1);
                if(i > 1) {
                    dp[i][j] = min(dp[i][j], dp[i-2][j]+1);
                    if(i > 2) {
                        dp[i][j] = min(dp[i][j], dp[i-3][j]+1);
                    }
                }
                if(j > 1) {
                    dp[i][j] = min(dp[i][j], dp[i][j-2]+1);
                    if(j > 2) {
                        dp[i][j] = min(dp[i][j], dp[i][j-3]+1);
                    }
                }
                if(i > 1 && j > 1) {
                    dp[i][j] = min(dp[i-2][j-2]+2, dp[i][j]);
                    if(i > 2 && j > 2) {
                        dp[i][j] = min(dp[i-3][j-3]+3, dp[i][j]);
                    }
                }
            }
        }
    }
    cout << dp[A.length()][B.length()] << "\n";
    return 0;
}
