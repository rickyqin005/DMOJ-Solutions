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
struct triple {
    int v,w,d;
    triple(){}
};
triple arr[500001];
ll maxRating = -INT_MAX;
void recurse(int node, ll rate) {
    if(arr[node].v != 0) {
        recurse(arr[node].v, rate+arr[node].d);
        recurse(arr[node].w, rate);
    }
    maxRating = max(maxRating, rate);
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(arr, 0, sizeof(arr));
    int N,R; cin >> N >> R;
    for(int i = 1,u,v,w,d; i <= (1<<N)-1; i++) {
        cin >> u >> v >> w >> d;
        arr[u].v = v;
        arr[u].w = w;
        arr[u].d = d;
    }
    recurse(1, R);
    cout << maxRating << "\n";
    return 0;
}