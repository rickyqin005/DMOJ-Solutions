#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef pair<int, pii> pipii;
pii a[1000001];
int dp[1000001];
bool comp(pii a, pii b) {return a.s < b.s;}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp, 0, sizeof(dp));
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> a[i].f >> a[i].s;
    sort(a+1,a+N+1, comp);
    for(int i = 1,pos = 0; i <= N; i++) {
        while(pos < a[i].s) {
            dp[pos+1] = max(dp[pos+1], dp[pos]);
            pos++;
        }
        dp[a[i].s] = max(dp[a[i].s], dp[a[i].f]+1);

    }
    int ans = 0;
    for(int i = 1; i <= 1000000; i++) ans = max(ans, dp[i]);
    cout << ans << "\n";
    return 0;
}