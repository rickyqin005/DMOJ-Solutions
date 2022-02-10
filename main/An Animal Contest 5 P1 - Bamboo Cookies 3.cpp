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

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N; cin >> N;
    int even = 0;
    int odd = 0;
    for(int i = 1,a; i <= N; i++) {
        cin >> a;
        if(a%2 == 0) even++;
        else odd++;
    }
    cout << even/2 + odd/2 << "\n";
    return 0;
}