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
pll arr[3001];
ll dis[3001];
bool vis[3001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dis, 0x7f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i].f >> arr[i].s;
    int X; cin >> X;
    dis[X] = 0;
    for(int i = 1; i <= N; i++) {
        ll minDis = 0x7f7f7f7f7f7f7f7f; int minIdx = -1;
        for(int j = 1; j <= N; j++) {
            if(vis[j]) continue;
            if(dis[j] < minDis) {
                minDis = dis[j];
                minIdx = j;
            }
        }
        vis[minIdx] = 1;
        for(int j = 1; j <= N; j++) {
            if(vis[j]) continue;
            dis[j] = min(dis[j], dis[minIdx] + (arr[minIdx].f-arr[j].f)*(arr[minIdx].f-arr[j].f) + (arr[minIdx].s-arr[j].s)*(arr[minIdx].s-arr[j].s));
        }
    }
    //for(int i = 1; i <= N; i++) {cout << dis[i] << " ";} cout << "\n";
    sort(dis+1, dis+N+1);
    int Q; cin >> Q; ll q;
    for(int i = 1; i <= Q; i++) {
        cin >> q;
        cout << upper_bound(dis+1, dis+N+1, q)-dis-1 << "\n";
    }
    return 0;
}
