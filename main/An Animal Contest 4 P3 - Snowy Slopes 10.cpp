#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
pll arr[100001];
pll slope[21];
ll yint[100001][21];
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}
unordered_map<ll, ll> umap;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N,M; cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> arr[i].f >> arr[i].s;
    for(int i = 1; i <= M; i++) {
        cin >> slope[i].f >> slope[i].s;
        ll g = ((slope[i].f>slope[i].s? gcd(slope[i].f,slope[i].s): gcd(slope[i].s,slope[i].f)));
        slope[i].f /= g;
        slope[i].s /= g;
        if(slope[i].s < 0) {
            slope[i].f *= -1;
            slope[i].s *= -1;
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            yint[i][j] = arr[i].s*slope[j].s + slope[j].f*(0-arr[i].f);
        }
    }
    /*for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cout << yint[i][j] << " ";
        } cout << "\n";
    } cout << "\n";*/
    ll ans = 0;
    for(int j = 1; j <= M; j++) {
        bool flag = true;
        for(int k = 1; k < j; k++) {
            if(slope[k].f == slope[j].f && slope[k].s == slope[j].s) {flag = false; break;}
        }
        if(!flag) continue;
        umap.clear();
        for(int i = 1; i <= N; i++) {
            umap[yint[i][j]]++;
        }
        for(pll freq: umap) {
            ans += freq.s*(freq.s-1)/2;
        }
    }
    cout << ans << "\n";
    return 0;
}