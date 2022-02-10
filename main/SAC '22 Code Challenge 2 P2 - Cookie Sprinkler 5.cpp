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
int cookie[501][501];
int sprinkle[501][501];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(cookie, 0, sizeof(cookie));
    memset(sprinkle, 0, sizeof(sprinkle));
    int N,Q; cin >> N >> Q;
    for(int i = 1,t,a,b,c,d; i <= Q; i++) {
        cin >> t;
        if(t == 1) {
            cin >> a >> b;
            cookie[a][b]++;
        } else if(t == 2) {
            cin >> a >> b >> c >> d;
            for(int j = a; j <= c; j++) {
                for(int k = b; k <= d; k++) {
                    sprinkle[j][k] += cookie[j][k];
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) ans += sprinkle[i][j];
    }
    cout << ans << "\n";
    return 0;
}