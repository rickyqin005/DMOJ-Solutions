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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    int ans = 0;
    while(N > 1) {
        if(N%2 == 0) {
            N /= 2;
            ans++;
        } else {
            int sqr = sqrt(N);
            bool flag = false;
            for(int i = 3; i <= sqr; i++) {
                if(N%i == 0) {
                    N -= N/i;
                    ans += i-1;
                    flag = true; break;
                }
            }
            if(!flag) {
                N--;
                ans += N;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}