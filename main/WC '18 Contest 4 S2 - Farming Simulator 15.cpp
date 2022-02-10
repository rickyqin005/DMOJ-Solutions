#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807
#define MAX_DOUBLE 1e18
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef vector<int> vii;
typedef vector<ll> vll;
#define MAXN 3000
ll dp[MAXN+1];
pll hole[MAXN+1];
bool comp(pii a, pii b) {
    return a.f < b.f;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    memset(dp, 0x7f, sizeof(dp));
    int N, H; cin >> N >> H;
    for(int i = 1,p,w; i <= N; i++) {
        cin >> p >> w;
        hole[i] = mp(p,w);
    }
    sort(hole+1, hole+N+1, comp);
    dp[0] = 0; ll cMax;
    for(int i = 1; i <= N; i++) {
        cMax = hole[i].s;
        for(int j = i; j <= N; j++) {
            cMax = max(cMax, hole[j].s);
            dp[j] = min(dp[j], (hole[j].f-hole[i].f)+max(2*(hole[j].f-hole[i].f),cMax)+dp[i-1]+(hole[i].f-hole[i-1].f));
        }
        //for(int j = 0; j <= N; j++) {cout << dp[j] << " ";}cout << "\n";
    }
    cout << dp[N]+(H-hole[N].f) << "\n";
    return 0;
}