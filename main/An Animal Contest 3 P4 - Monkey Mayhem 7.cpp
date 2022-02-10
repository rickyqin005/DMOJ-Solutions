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
unordered_map<int, int> umapN;
unordered_map<int, int> umapM;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N,M; cin >> N >> M;
    for(int i = 1,a; i <= N; i++) {
        cin >> a;
        if(a == -1) continue;
        umapN[a-i]++;
    }
    for(int j = 1,a; j <= M; j++) {
        cin >> a;
        if(a == -1) continue;
        umapM[a-j]++;
    }
    int ans = 0;
    for(pii val: umapN) {
        ans += min(val.s, umapM[val.f]);
    }
    cout << ans << "\n";
    return 0;
}