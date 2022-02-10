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
typedef pair<pii, int> piipi;
typedef vector<int> vii;
typedef vector<ll> vll;
#define MAXT 8640
#define MAXN 100
double dp[MAXT+1];
int t[MAXN+1];
double val[MAXN+1];
int A0 = 0;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    memset(dp, 0, sizeof(dp));
    memset(t, 0, sizeof(t));
    int N, M, T; cin >> N >> M >> T;
    for(int i = 1; i <= N; i++) {cin >> t[i];}
    for(int i = 1,A; i <= M; i++) {
        cin >> A;
        if(A == 0) A0++;
        for(int j = 1,idx; j <= A; j++) {
            cin >> idx;
            val[idx] += 1.0/A;
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = T-t[i]; j >= 0; j--) {
            dp[j+t[i]] = max(dp[j+t[i]], dp[j]+val[i]);
        }
    }
    double ans = 0;
    for(int i = 0; i <= T; i++) {ans = max(ans, dp[i]);}
    printf("%.02f\n", ans+A0);
    return 0;
}