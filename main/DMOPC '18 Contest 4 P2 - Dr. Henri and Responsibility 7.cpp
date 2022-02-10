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
    int arr[N];
    int len = 700*N;
    bool dp[len+1];
    fill_n(dp, len+1, false);
    dp[0] = true;
    int sum = 0;
    for(int i = 0,a; i < N; i++) {
        cin >> a;
        sum += a;
        for(int j = len-a; j >= 0; j--) {
            if(dp[j]) dp[j+a] = true;
        }
    }
    int ans = MAX_INT;
    for(int i = 0; i <= len; i++) {
        if(dp[i]) {
            ans = min(ans, abs((sum-i)-i));
        }
    }
    cout << ans << "\n";
    return 0;
}