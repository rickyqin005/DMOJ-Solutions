#include<bits/stdc++.h>
#include<iostream>
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

#define MAXT 5000
#define MAXN 500
int dp[MAXT+1];
int brk[MAXN+1];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int T, N; cin >> T >> N;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(int i = 0; i < N; i++) {
        cin >> brk[i];
    }
    for(int i = 0; i < N; i++) {
        for(int j = T-brk[i]; j >= 0; j--) {
            if(dp[j] == -1) continue;
            if(dp[j+brk[i]] != -1) continue;
            dp[j+brk[i]] = i;
        }
    }
    int ans[N];
    memset(ans, -1, sizeof(ans));
    for(int i = T; i >= 0; i--) {
        if(dp[i] != -1) {
            for(; i > 0; i -= brk[dp[i]]) {
                ans[dp[i]] = i-brk[dp[i]];
            }
            break;
        }
    }
    int sum = 0;
    for(int i = 0; i < N; i++) {
        if(ans[i] == -1) {
            ans[i] = sum;
            sum += brk[i];
        }
    }
    for(int i = 0; i < N; i++) {cout << ans[i] << " ";} cout << "\n";
    return 0;
}