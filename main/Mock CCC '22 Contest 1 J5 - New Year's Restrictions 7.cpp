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
pii arr[325];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N,M; cin >> N >> M;
    for(int i = 1; i <= M; i++) cin >> arr[i].f >> arr[i].s;
    int ans = 0;
    for(int num = 1; num < (1<<N); num++) {
        bool flag = true;
        for(int j = 1; j <= M; j++) {
            if((num&(1<<(arr[j].f-1))) && (num&(1<<(arr[j].s-1)))) {
                flag = false; break;
            }
        }
        if(flag) ans = max(ans, (int)(bitset<32>(num).count()));
    }
    cout << ans << "\n";
    return 0;
}