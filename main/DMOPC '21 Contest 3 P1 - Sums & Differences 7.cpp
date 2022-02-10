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
ll res[20001];
ll ans[20001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i = 2; i <= N; i++) {
        cout << "? " << i-1 << " " << i << endl;
        cin >> res[i];
        if(i >= 3) ans[i] = res[i-1]-res[i];
    }

    ll last;
    cout << "? " << 1 << " " << 2 << endl;
    cin >> last;
    last += ans[3];
    last /= 2;
    ans[2] = last;
    ans[1] = res[2]+last;

    cout << "!";
    for(int i = 1; i <= N; i++) cout << " " << ans[i];
    cout << endl;
    return 0;
}