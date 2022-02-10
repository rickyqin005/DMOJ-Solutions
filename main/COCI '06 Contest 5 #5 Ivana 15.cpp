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
typedef vector<int> vii;
typedef vector<ll> vll;
int N;
int arr[101];
int psa[100];
int dp[100][100];
int sum(int l, int r) {return psa[r]-psa[l-1];}
bool check(int x) {
    memset(dp, 0, sizeof(dp));
    memset(psa, 0, sizeof(psa));
    for(int i = x+1, n = 1; n < N; i++, n++) {
        if(i > N) i = 1;
        dp[n][n] = (arr[i]%2==1);
        psa[n] = psa[n-1]+dp[n][n];
    }
    for(int len = 1; len+1 < N; len++) {
        for(int l = 1,r = l+len; r < N; l++, r++) {
            dp[l][r] = max(sum(l,r)-dp[l+1][r], sum(l,r)-dp[l][r-1]);
        }
    }
    /*for(int i = 1; i < N; i++) {
        for(int j = 1; j < N; j++) {cout << dp[i][j] << " ";} cout << "\n";
    } cout << "\n";*/
    return sum(1,N-1)-dp[1][N-1]+(arr[x]%2) > dp[1][N-1];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp, 0, sizeof(dp));
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        arr[i] = (arr[i]%2==1);
    }
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        ans += check(i);
    }
    cout << ans << "\n";
    return 0;
}