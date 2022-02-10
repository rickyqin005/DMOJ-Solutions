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

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    double PI = 3.1415926535;
    double L,H,W,D; cin >> L >> H >> W >> D;
    double ans = L*W*H - PI*(D/2.0)*(D/2.0)*H;
    printf("%.06f\n", ans);
    return 0;
}