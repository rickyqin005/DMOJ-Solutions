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
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int t = 1,a,b,c; t <= T; t++) {
        cin >> a >> b >> c;
        if((a*1+b*2+c*3)%2 == 0) {
            if(c > 0) {
                if(a >= c) {
                    cout << "YES" << "\n";
                } else cout << "NO" << "\n";
            } else {
                if(a%2 == 0 && b%2 == 0) cout << "YES" << "\n";
                else if(a%2 == 1 && b%2 == 0) cout << "NO" << "\n";
                else if(a%2 == 0 && b%2 == 1) {
                    if(a > 0) cout << "YES" << "\n";
                    else cout << "NO" << "\n";
                }
                else if(a%2 == 1 && b%2 == 1) cout << "NO" << "\n";
            }
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}