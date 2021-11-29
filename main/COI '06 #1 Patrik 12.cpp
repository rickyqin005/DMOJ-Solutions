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
pii stk[500001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(stk, 0, sizeof(stk));
    int N; cin >> N;
    ll ans = 0;
    int top = 0;
    stk[top] = mp(INT_MAX, 0);
    top++;
    int curr; cin >> curr;
    stk[top] = mp(curr,1);
    for(int i = 2; i <= N; i++) {
        cin >> curr;
        while(curr > stk[top].f) {
            ans += stk[top].s;
            stk[top] = mp(0,0);
            top--;
        }
        if(top > 0 && curr < stk[top].f) ans++;
        if(curr == stk[top].f) {
            ans += stk[top].s;
            if(top > 1) ans++;
            stk[top].s++;
        } else if(curr < stk[top].f) {
            top++;
            stk[top] = mp(curr,1);
        }
    }
    cout << ans << "\n";
    return 0;
}