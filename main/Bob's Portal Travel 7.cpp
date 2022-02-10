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
int x[200002];
int cycle[200002];
bool vis[200002];
int idx[200002];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(x, 0, sizeof(x));
    memset(cycle, 0, sizeof(cycle));
    memset(vis, 0, sizeof(vis));
    memset(idx, 0, sizeof(idx));
    int N; cin >> N; ll K; cin >> K;
    for(int i = 1; i <= N; i++) cin >> x[i];
    int loc = 1;
    ll len = 1;
    cycle[1] = 1;
    vis[1] = 1;
    idx[1] = 1;
    while(true) {
        loc = x[loc];
        if(idx[loc]) break;
        len++;
        cycle[len] = loc;
        idx[loc] = len;
    }
    //for(int i = 1; i <= len; i++) {cout << cycle[i] << " ";} cout << "\n";
    //for(int i = 1; i <= N; i++) {cout << idx[i] << " ";} cout << "\n";
    int repeat = x[cycle[len]];
    //cout << len << " " << repeat << "\n";
    if(K+1 <= idx[repeat]) cout << cycle[K+1] << "\n";
    else cout << cycle[idx[repeat]+(K-idx[repeat]+1)%(len-idx[repeat]+1)] << "\n";
    return 0;
}