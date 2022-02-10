#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;
ll difa[100001];
ll difb[100001];
ll difc[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(difa, 0, sizeof(difa));
    memset(difb, 0, sizeof(difb));
    memset(difc, 0, sizeof(difc));
    int N,T; cin >> N >> T;
    for(int i = 1,l,r,a,b,c; i <= N; i++) {
        cin >> l >> r >> a >> b >> c;
        difa[l+2] += 2*a;
        difa[r+1] -= 2*a;
        difb[l+1] += a;
        difb[r+1] -= a;
        difb[r+1] -= (ll)2*a*(r-l-1);
        difc[r+1] -= (ll)a*(r-l)*(r-l);
        difb[l+1] += b;
        difb[r+1] -= b;
        difc[r+1] -= (ll)b*(r-l);
        difc[l] += c;
        difc[r+1] -= c;
    }
    for(int i = 1; i <= T; i++) {
        difa[i] += difa[i-1];
        difb[i] += difb[i-1]+difa[i];
        difc[i] += difc[i-1]+difb[i];
        cout << difc[i] << " ";
    }
    cout << "\n";
    return 0;
}