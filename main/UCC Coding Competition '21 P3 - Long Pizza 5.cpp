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
int diff[10000002];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(diff, 0, sizeof(diff));
    int N; cin >> N;
    int x,y; cin >> x >> y;
    int R; cin >> R;
    for(int i = 1,l,r; i <= R; i++) {
        cin >> l >> r;
        diff[l]++;
        diff[r+1]--;
    }
    ll ans = 0,curr = 0;
    for(int i = 1; i <= N; i++) {
        curr += diff[i];
        if(i >= x && i <= y) ans += curr;
    }
    cout << ans << endl;
    return 0;
}