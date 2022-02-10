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
unordered_set<string> dict;
int dp[2001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; string str;
    for(int i = 1; i <= N; i++) {
        cin >> str; dict.insert(str);
    }
    for(int i = 1; i <= 10; i++) {
        memset(dp, 0x7f, sizeof(dp));
        dp[0] = 0;
        cin >> str;
        N = str.length();
        for(int j = 0; j <= N; j++) {
            if(dp[j] != 0x7f7f7f7f) {
                for(int len = 1; j+len <= N; len++) {
                    if(dict.count(str.substr(j+1-1, len))) {
                        dp[j+len] = min(dp[j+len], dp[j]+1);
                    }
                }
            }
        }
        cout << (dp[N]-1) << "\n";
    }
    return 0;
}