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
ll arr[200001];
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}
vector<pll> vect;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(arr, 0, sizeof(arr));
    int N,Q; cin >> N >> Q;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    arr[0] = 1;
    for(int i = 1; i <= N; i++) {
        arr[i] = arr[i-1]*arr[i]/((arr[i]>arr[i-1]?gcd(arr[i], arr[i-1]):gcd(arr[i-1], arr[i])));
        if(arr[i] > 1000000000) break;
    }
    for(int i = 1; i <= N; i++) {
        if(arr[i] == 0) break;
        if(arr[i] != arr[i-1]) vect.pb(mp(arr[i], i));
    }
    for(int i = 1,q; i <= Q; i++) {
        cin >> q;
        bool flag = true;
        for(pll lcm: vect) {
            if(q%lcm.f != 0) {cout << lcm.s << "\n"; flag = false; break;}
        }
        if(flag) cout << -1 << "\n";
    }

    return 0;
}