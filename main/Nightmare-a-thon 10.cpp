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
int pref[500010][11];
int suff[500010][11];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(pref, 0, sizeof(pref));
    memset(suff, 0, sizeof(suff));
    int N,Q; cin >> N >> Q;
    for(int i = 1,a; i <= N; i++) {
        cin >> a;
        pref[i][a]++;
        suff[i][a]++;
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= 10; j++) pref[i][j] += pref[i-1][j];
    }
    for(int i = N; i >= 1; i--) {
        for(int j = 1; j <= 10; j++) suff[i][j] += suff[i+1][j];
    }
    for(int i = 1,a,b; i <= Q; i++) {
        cin >> a >> b;
        for(int j = 10; j >= 1; j--) {
            if(pref[a-1][j] || suff[b+1][j]) {
                cout << j << " " << pref[a-1][j]+suff[b+1][j] << "\n"; break;
            }
        }
    }
    return 0;
}
