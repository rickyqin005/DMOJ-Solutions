#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef pair<int, pii> pipii;
int arr[7];
bool vis[7];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(vis, 0, sizeof(vis));
    int A,B,C;
    for(int i = 0; i < 7; i++) cin >> arr[i];
    sort(arr, arr+7);
    A = arr[0]; B = arr[1];
    vis[0] = 1; vis[1] = 1;
    for(int i = 2; i < 7; i++) {
        if(!vis[i] && arr[i] == A+B) {
            vis[i] = 1; break;
        }
    }
    for(int i = 2; i < 7; i++) {
        if(!vis[i]) {
            C = arr[i];
            vis[i] = 1; break;
        }
    }
    cout << A << " " << B << " " << C << "\n";
    return 0;
}