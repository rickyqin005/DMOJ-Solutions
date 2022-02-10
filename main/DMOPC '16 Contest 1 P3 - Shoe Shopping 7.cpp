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
typedef vector<int> vii;
typedef vector<ll> vll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int N; cin >> N;
    if(N == 1) {
        double s1; cin >> s1;
        printf("%.01f\n", s1);
    } else if(N == 2) {
        double s1, s2; cin >> s1 >> s2;
        printf("%.01f\n", min(s1+s2, max(s1,s2)+min(s1,s2)*0.5));
    } else {
        double shoe[N+1];
        memset(shoe, 0, sizeof(shoe));
        for(int i = 1; i <= N; i++) {cin >> shoe[i];}
        double dp[N+1];
        memset(dp, 0, sizeof(dp));
        dp[1] = shoe[1];
        dp[2] = min(shoe[1]+shoe[2], max(shoe[1],shoe[2])+min(shoe[1],shoe[2])*0.5);
        for(int i = 3; i <= N; i++) {
            dp[i] = min(min(dp[i-1]+shoe[i], dp[i-2]+max(shoe[i-1],shoe[i])+min(shoe[i-1],shoe[i])*0.5),
                        dp[i-3]+shoe[i-2]+shoe[i-1]+shoe[i]-min(min(shoe[i-2], shoe[i-1]), shoe[i]));
        }
        //for(int i = 0; i <= N; i++) {cout << dp[i] << " ";} cout << "\n";
        printf("%.01f\n", dp[N]);
    }
    return 0;
}