#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef pair<int, pii> pipii;
int dp[51];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    fill(dp, dp+sizeof(dp), 1);
    string s; cin >> s; int N = s.length();
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j < i; j++) {
            if(s[i-1] > s[j-1]) dp[i] = max(dp[i], dp[j]+1);
        }
    }
    int ans = 1;
    for(int i = 1; i <= N; i++) {ans = max(ans, dp[i]);}
    cout << 26-ans << "\n";
    return 0;
}