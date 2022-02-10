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
ll arr[200001];
int nxt[200001];
pair<ll, int> stk[200001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N,Q; cin >> N >> Q; ll curr;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    int top = 0;
    stk[0] = mp(0LL, 0);
    for(int i = 1; i <= N; i++) {
        if(top == 0 || arr[i] >= stk[top].f) {
            top++;
            stk[top] = mp(arr[i], i);
        } else {
            while(top != 0 && arr[i] < stk[top].f) {
                nxt[stk[top].s] = i;
                top--;
            }
            top++;
            stk[top] = mp(arr[i], i);
        }
    }
    for(int i = 1; i <= top; i++) nxt[stk[i].s] = 1000000000;
    ll v,l,r;
    for(int i = 1; i <= Q; i++) {
        cin >> v >> l >> r;
        for(int j = l; j <= r && v > 0; j = nxt[j]) v = v%arr[j];
        cout << v << "\n";
    }
    return 0;
}