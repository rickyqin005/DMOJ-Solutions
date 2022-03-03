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
ll a[200001];
ll b[200001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; ll K; cin >> N >> K;
    for(int i = 1; i <= N; i++) cin >> a[i];
    for(int i = 1; i <= N; i++) cin >> b[i];
    sort(a+1, a+N+1);
    sort(b+1, b+N+1);
    ll ans = 0;
    for(int i = 1; i < N; i++) ans = (ans+(ll)a[i]*b[i])%MOD;
    if(a[N] > b[N]) swap(a[N], b[N]);
    int origa = a[N];
    int origb = b[N];
    
    a[N] += min(b[N]-a[N], K); K -= a[N]-origa;
    if(a[N] == b[N]) {
        a[N] += K/2;
        b[N] += K/2 + (K%2);
    }
    ans = (ans+(ll)a[N]*b[N])%MOD;
    cout << ans << "\n";
    return 0;
}