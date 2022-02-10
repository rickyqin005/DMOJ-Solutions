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
ll psa[2000001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(psa, 0, sizeof(psa));
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> psa[i];
        psa[i+N] = psa[i];
    }
    for(int i = 1; i <= 2*N; i++) psa[i] += psa[i-1];

    for(int i = 1; i <= N; i++) {
        int low = i, high = N+i-1, mid; ll ans = MAX_LONG;
        while(low < high) {
            mid = (low+high)/2;
            if(psa[N+i-1]-psa[mid] <= psa[mid]-psa[i-1]) {
                high = mid;
            } else {
                low = mid+1;
            }
            ans = min(ans, abs((psa[N+i-1]-psa[mid]) - (psa[mid]-psa[i-1])));
        }
        cout << ans;
        if(i != N) cout << " ";
    }
    cout << "\n";
    return 0;
}