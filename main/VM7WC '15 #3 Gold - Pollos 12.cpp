#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 888888877777777
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;
typedef pair<int, bool> pib;
int N,K;
pib arr[100001];
bool check(int F) {
    for(int i = 1,gap = 0, cnt = 0; i <= N; i++) {
        gap += arr[i].f-arr[i-1].f;
        if(gap > F) return false;
        if(arr[i].s) {
            gap = 0; cnt++;
        } else if(i != N && gap+arr[i+1].f-arr[i].f > F) {
            gap = 0; cnt++;
        }
        if(cnt > K) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    arr[0] = mp(0,1);
    for(int i = 1; i <= N; i++) cin >> arr[i].f >> arr[i].s;
    arr[N].s = 1;
    int low = 1, high = arr[N].f+1, mid, ans = INT_MAX;
    while(low < high) {
        mid = (low+high)/2;
        if(check(mid)) {
            ans = min(ans, mid);
            high = mid;
        } else {
            low = mid+1;
        }
    }
    if(ans == INT_MAX) cout << "DEA Bust!" << "\n";
    else cout << ans << "\n";
    return 0;
}