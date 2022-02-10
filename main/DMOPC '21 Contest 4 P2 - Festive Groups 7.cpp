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
int arr[2000001];
int mult[5000001];
bool vis[5000001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(arr, 0, sizeof(arr));
    memset(mult, 0, sizeof(mult));
    memset(vis, 0, sizeof(vis));
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    sort(arr+1, arr+N+1, greater<int>());
    for(int i = 1; i <= N; i++) {
        if(arr[i] != arr[i-1]) {
            for(int j = arr[i]; j <= 5000000; j += arr[i]) mult[j] = i;
        }
    }
    for(int i = 1; i <= N; i++) {
        vis[mult[arr[i]]] = true;
    }
    int ans = 0;
    for(int i = 1; i <= N; i++) ans += vis[i];
    cout << ans << "\n";
    return 0;
}