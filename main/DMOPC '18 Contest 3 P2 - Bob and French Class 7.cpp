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

#define MAXN 100000
int dp0[MAXN+1];
int dp1[MAXN+1];
int dp2[MAXN+1];
int fr[MAXN+1];
int en[MAXN+1];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 0; i <= N; i++) {dp0[i] = dp1[i] = dp2[i] = -INT_MAX;}
    for(int i = 1; i <= N; i++) {cin >> fr[i];}
    for(int i = 1; i <= N; i++) {cin >> en[i];}
    dp0[0] = 0;
    dp0[1] = en[1];
    dp1[1] = fr[1];
    for(int i = 2; i <= N; i++) {
        dp0[i] = max(max(dp0[i-1], dp1[i-1]), dp2[i-1])+en[i];
        dp1[i] = dp0[i-1]+fr[i];
        dp2[i] = dp1[i-1]+fr[i];
    }
    cout << max(max(dp0[N], dp1[N]), dp2[N]) << "\n";
    return 0;
}