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
vector<int> dp;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N; cin >> N;
    for(int i = 1,a; i <= N; i++) {
        cin >> a;
        auto it = lower_bound(dp.begin(), dp.end(), a);
        if(it == dp.end()) dp.pb(a);
        else *it = a;
    }
    cout << dp.size() << "\n";
    return 0;
}
