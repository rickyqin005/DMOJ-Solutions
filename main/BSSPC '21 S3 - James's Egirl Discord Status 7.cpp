#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
ll dp[1000001];
ll arr[1000001];
ll pref[1000001];
ll sum(int l, int r) {return pref[r]-pref[l-1];}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp, 0, sizeof(dp));
    memset(pref, 0, sizeof(pref));
    int N,K; cin >> N >> K;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    for(int i = 1; i <= N; i++) pref[i] = pref[i-1]+arr[i];
    for(int i = K; i <= N; i++) {
        dp[i] = max(dp[i-K]+sum(i-K+1, i), sum(i-K+1, i));
    }
    ll ans = 0;
    for(int i = 0; i <= N; i++) ans = max(ans, dp[i]);
    cout << ans << "\n";
    //for(int i = 1; i <= N; i++) {cout << dp[i] << " ";} cout << "\n";
    return 0;
}