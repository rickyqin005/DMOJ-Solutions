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
pii arr[200001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(arr, -1, sizeof(arr));
    int N,M,K; cin >> N >> M >> K;
    for(int i = 1,a,b,c; i <= K; i++) {
        cin >> a >> b >> c;
        if(c > arr[b].f) {
            arr[b].f = c;
            arr[b].s = a;
        }
    }
    for(int i = 1; i <= N; i++) cout << arr[i].s << " ";
    cout << "\n";
    return 0;
}