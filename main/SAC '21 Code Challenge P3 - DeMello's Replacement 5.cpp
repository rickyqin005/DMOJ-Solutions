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
int arr[100001];
ll exp(int b, int e) {
    ll ans = 1;
    for(int i = 1; i <= e; i++) ans *= b;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N,P; cin >> N >> P;
    ll mins = MAX_LONG;
    ll maxs = -9223372036854775806;
    string minn = "";
    string maxn = "";
    for(int i = 1,m,cs,e; i <= N; i++) {
        string name; cin >> name;
        cin >> m >> cs >> e;
        ll score = (ll)((ll)(4.0*sqrt(m))+(ll)3*exp(cs,P)-4*e);
        if(score < mins) {
            mins = score;
            minn = name;
        }
        if(score > maxs) {
            maxs = score;
            maxn = name;
        }
    }
    cout << maxn << " " << maxs << "\n";
    cout << minn << " " << mins << "\n";

    return 0;
}