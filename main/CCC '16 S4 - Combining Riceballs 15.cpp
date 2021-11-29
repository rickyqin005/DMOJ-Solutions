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
int arr[401];
int pref[401];
bool dp[401][401];
int query(int l, int r) {
    return pref[r]-pref[l-1];
}
bool check(int l, int r) {
    int sum1 = query(l,r), sum2 = 0;
    int pos1 = r, pos2 = r;
    while(true) {
        sum1 -= arr[pos1];
        sum2 += arr[pos2];
        if(sum1 <= sum2) break;
        pos1--; pos2--;
    }
    pos1 = pos2-1;
    for(; pos1 >= l; sum1 -= arr[pos1], pos1--) {
        while(sum2 > sum1) {
            sum2 -= arr[pos2];
            pos2++;
        }
        if(sum1 == sum2 && dp[l][pos1] && dp[pos2][r]) {
            if(pos1+1 == pos2) return true;
            if(dp[pos1+1][pos2-1]) return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(arr, 0, sizeof(arr));
    memset(dp, 0, sizeof(dp));
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        dp[i][i] = arr[i];
        pref[i] = pref[i-1]+arr[i];
    }
    for(int j = 1; j < N; j++) {
        if(arr[j] == arr[j+1]) dp[j][j+1] = 1;
    }
    for(int i = 2; i < N; i++) {
        for(int j = 1; j+i <= N; j++) {
            dp[j][j+i] = check(j,j+i);
        }
    }
    int ans = 0;
    for(int i = 1,sum; i <= N; i++) {
        sum = 0;
        for(int j = i; j <= N; j++) {
            sum += arr[j];
            if(dp[i][j]) ans = max(ans, sum);
        }
    }
    cout << ans << "\n";
    return 0;
}