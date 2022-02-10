#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;
int dp[51];
pii card[30001];
int arr[51][1001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int B,N,D; cin >> B >> N >> D;
    for(int i = 1; i <= N; i++) cin >> card[i].f >> card[i].s;
    for(int i = 1,a,b,x,y; i <= D; i++) {
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));
        cin >> a >> b >> x >> y;
        card[a].f = b;
        for(int j = x; j <= y; j++) arr[card[j].f][card[j].s]++;
        for(int j = B,mx; j >= 1; j--) {
            mx = B/j;
            for(int k = 1000; k >= 1; k--) {
                for(int n = 1; n <= arr[j][k] && mx > 0; n++, mx--) {
                    for(int l = B-j; l >= 0; l--) dp[l+j] = max(dp[l+j], dp[l]+k);
                }
            }
        }
        cout << dp[B] << "\n";
    }
    return 0;
}