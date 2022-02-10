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
string str;
vector<int> posI;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    cin >> str;
    for(int i = 0; i < 2*N; i++) {
        if(str[i] == 'I') posI.pb(i+1);
    }
    if(posI.size() != N) {cout << -1 << "\n"; return 0;}
    ll ans = 0;
    for(int i = 1,idx = 0; i <= 2*N; i += 2, idx++) {
        ans += abs(i-posI[idx]);
    }
    cout << ans << "\n";
    return 0;
}