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
int psa[1000001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N,Q; cin >> N >> Q;
    for(int i = 1; i <= N; i++) {
        cin >> psa[i];
        psa[i] += psa[i-1];
    }
    for(int i = 1,l,r; i <= Q; i++) {
        cin >> l >> r;
        cout << (psa[r]-psa[l-1])/(r-l+1) << "\n";
    }
    return 0;
}