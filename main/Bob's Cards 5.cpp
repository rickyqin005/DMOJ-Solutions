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
int a[200002];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(a, 0, sizeof(a));
    int N; cin >> N;
    int pos = 1;
    int ans = 0;
    int i,next;
    for(i = 1; i <= N; i++) cin >> a[i];
    for(i = 1; i <= N; i++) {
        for(next = pos; next <= N; next++) {
            if(a[next] == i) break;
        }
        if(next == N+1) break;
        ans += (next-pos);
        pos = next+1;
    }
    if(i == 1 && next == N+1) {cout << -1 << "\n"; return 0;}
    if(pos != N+1) ans += N-pos+1;
    cout << ans << "\n";
    return 0;
}