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
int arr[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    int ans = 0,curr = 0;
    for(int i = 1; i <= N; i++) {
        curr = 0;
        for(; i <= N && arr[i]%2 == 0; i++) {
            curr += arr[i];
        }
        ans = max(ans, curr);
    }
    cout << ans << endl;
    return 0;
}