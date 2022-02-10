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
int a[1000001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N,H,P; cin >> N >> H >> P;
    a[0] = 0;
    for(int i = 1; i <= N; i++) cin >> a[i];
    sort(a+1, a+N+1);
    ll ans = 0;
    for(int i = 1; i <= N; i++) {
        ans += min((ll)H*(a[i]-a[i-1]),(ll)P*(a[i]-a[i-1])*(N-i+1));
    }
    cout << ans << "\n";
    return 0;
}