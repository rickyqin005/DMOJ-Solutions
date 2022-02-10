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
ll arr[100001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N; cin >> N;
    ll arrSum = 0;
    for(int i = 2; i <= N; i++) {
        cout << "? 1 " << i << endl;
        cin >> arr[i];
        arrSum += arr[i];
    }
    for(int i = 1; i <= N; i++) {
        if((ll)i*((ll)N*(N+1)/2-i) == arrSum) {
            arr[1] = i; break;
        }
    }
    cout << "! " << arr[1];
    for(int i = 2; i <= N; i++) cout << " " << arr[i]/arr[1];
    cout << endl;
    return 0;
}