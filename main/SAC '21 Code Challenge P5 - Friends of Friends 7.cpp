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
int par[100001];
int wei[100001];
int get(int a) {
    if(par[a] != a) par[a] = get(par[a]);
    return par[a];
}
bool join(int a, int b) {
    a = get(a); b = get(b);
    if(a != b) {
        if(wei[a] > wei[b]) {
            par[b] = a; wei[a] += wei[b];
        } else {
            par[a] = b; wei[b] += wei[a];
        }
        return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N,Q; cin >> N >> Q;
    for(int i = 1; i <= N; i++) wei[i] = 1;
    for(int i = 1; i <= N; i++) par[i] = i;
    for(int i = 1,t,u,v,x; i <= Q; i++) {
        cin >> t;
        if(t == 1) {
            cin >> u >> v;
            join(u,v);
        } else {
            cin >> x;
            cout << wei[get(x)] << "\n";
        }
    }
    return 0;
}