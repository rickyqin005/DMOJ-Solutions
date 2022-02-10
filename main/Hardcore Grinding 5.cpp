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
    for(int i = 1,a,b; i <= N; i++) {
        cin >> a >> b;
        diff[a]++;
        diff[b]--;
    }
    int ans = 0;
    for(int i = 1,curr = 0; i <= 10000000; i++) {
        curr += diff[i];
        ans = max(ans, curr);
    }
    cout << ans << "\n";
    return 0;
}