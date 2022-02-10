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
typedef pair<ll, ll> pll;
int arr[100001];
int freq[101];
int freq_rev[101];
ll dp2[101];
ll dp3[101];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(freq, 0, sizeof(freq));
    memset(freq_rev, 0, sizeof(freq_rev));
    memset(dp2, 0, sizeof(dp2));
    memset(dp3, 0, sizeof(dp3));
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    for(int i = N; i >= 1; i--) freq_rev[arr[i]]++;
    ll ans = 0;
    for(int i = 1; i <= N; i++) {
        freq_rev[arr[i]]--;
        if(i >= 3) {
            for(int j = 100-arr[i]; j >= 1; j--) {
                dp3[j+arr[i]] += dp2[j];
            }
        }
        if(i >= 2) {
            for(int j = 100-arr[i]; j >= 1; j--) {
                dp2[j+arr[i]] += freq[j];
            }
        }
        freq[arr[i]]++;
        for(int j = 1; j <= 100; j++) {
            ans += dp3[j]*freq_rev[j];
        }
        /*for(int i = 1; i <= 10; i++) {cout << freq[i] << " ";} cout << "\n";
        for(int i = 1; i <= 10; i++) {cout << dp2[i] << " ";} cout << "\n";
        for(int i = 1; i <= 10; i++) {cout << dp3[i] << " ";} cout << "\n\n";*/
        memset(dp3, 0, sizeof(dp3));
    }
    cout << ans << "\n";
    return 0;
}