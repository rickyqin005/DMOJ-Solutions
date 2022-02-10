#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 100000
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef pair<int, pii> pipii;
int a[201];
ll dp[201][201];
int N; bool flag = 0;
int valid(int l, int r) {
    if(a[l] == -1) {
        if(a[r] == -1) return 3;
        else if(a[r]%2 == 0) return 1;
    } else if(a[r] == -1) {
        if(a[l]%2 == 1) return 1;
    } else if(a[r]-a[l] == 1 && a[r]%2 == 0) return 1;
    return 0;
}
ll solve(int l, int r) {
    if(l > r) return 1;
    if(dp[l][r] != -1) return dp[l][r];
    dp[l][r] = 0;
    for(int k = l+1; k <= r; k+=2) {
        dp[l][r] += solve(l+1, k-1)*solve(k+1,r)*valid(l,k);
        if(dp[l][r] >= MOD) {
            if(l == 1 && r == N) flag = 1;
            dp[l][r] %= MOD;
        }
    }
    return dp[l][r];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(a, 0, sizeof(a));
    memset(dp, -1, sizeof(dp));
    cin >> N;
    if(N%2 == 1) {cout << "0" << endl; return 0;}
    string str; cin >> str;
    for(int i = 1; i <= N; i++) {
        switch(str.at(i-1)) {
        case '(': a[i] = 1; break;
        case ')': a[i] = 2; break;
        case '[': a[i] = 3; break;
        case ']': a[i] = 4; break;
        case '{': a[i] = 5; break;
        case '}': a[i] = 6; break;
        case '?': a[i] = -1; break;
        }
    }
    ll ans = solve(1,N);
    if(flag) printf("%05lld\n", ans);
    else printf("%lld\n", ans);
    return 0;
}