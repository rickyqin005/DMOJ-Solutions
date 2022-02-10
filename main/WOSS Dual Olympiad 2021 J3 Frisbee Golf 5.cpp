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
int arr[7] = {1000, 500, 100, 50, 10, 5, 1};
ll ans[7] = {0, 0, 0, 0, 0, 0, 0};
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll D; cin >> D;
    ans[6] += D/1000;
    D %= 1000;
    for(int i = 1; i < 7; i++) {
        while(D >= arr[i]) {
            ans[6-i]++;
            D -= arr[i];
        }
    }
    for(int i = 0; i < 7; i++) {cout << ans[i] << " ";} cout << "\n";
}