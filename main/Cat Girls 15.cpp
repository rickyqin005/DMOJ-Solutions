#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef vector<int> vii;
typedef vector<ll> vll;
ll pos[500001];
ll val[500001];
ll dp[500001];
ll pma[500001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; ll W; cin >> N >> W;
    memset(pos, 0, sizeof(pos));
    memset(val, 0, sizeof(pos));
    memset(dp, 0, sizeof(dp));
    memset(pma, 0, sizeof(pma));
    char t; int p,c;
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        cin >> t;
        if(t == 'A') {
            cin >> p >> c;
            cnt++;
            pos[cnt] = pos[cnt-1]+p;
            val[cnt] = val[cnt-1]+c;
            dp[cnt] = val[cnt]-val[lower_bound(pos, pos+cnt+1, max(pos[cnt]-W,(ll)0))-pos];
            pma[cnt] = max(pma[cnt-1], dp[cnt]);
            cout << pma[cnt] << "\n";
        } else {
            cnt--;
        }
    }
    return 0;
}