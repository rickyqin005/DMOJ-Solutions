#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;
ll ans1[100001];
unordered_map<int, ll> ans2;
ll solve(int N) {
    if(N <= 100000) {
        if(ans1[N] != 0) return ans1[N];
    } else if(ans2[N] != 0) return ans2[N];
    ll ans = 0;
    int sqr = (int)sqrt(N);
    int pre = N,cur;
    for(int i = 2; i <= sqr; i++) {
        cur = N/i;
        ans += solve(cur);
        ans += (pre-cur)*solve(i-1);
        pre = cur;
    }
    cur = N/(sqr+1);
    if(N/sqr != sqr) ans += (pre-cur)*solve(sqr);
    if(N <= 100000) ans1[N] = ans;
    else ans2[N] = ans;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(ans1, 0, sizeof(ans1));
    int N; cin >> N;
    ans1[1] = 1; ans1[2] = 1; ans1[3] = 2; ans1[4] = 3;
    cout << solve(N) << "\n";
    return 0;
}