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
#define MOD 1000000007
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef vector<int> vii;
typedef vector<ll> vll;
#define MAXA 25000
int arr[101];
bool dp[25001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp, 0, sizeof(dp));
    int T; cin >> T;
    for(int i = 0,N,ans,val; i < T; i++) {
        memset(dp, 0, sizeof(dp));
        dp[0] = true;
        cin >> N;
        for(int j = 1; j <= N; j++) {cin >> arr[j];}
        sort(arr+1,arr+N+1);
        ans = N;
        for(int j = 1; j <= N; j++) {
            if(dp[arr[j]]) {
                ans--; continue;
            }
            for(int k = 0; k <= MAXA-arr[j]; k++) {
                if(dp[k]) dp[k+arr[j]] = true;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}