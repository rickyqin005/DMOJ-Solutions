#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
int ask(int p, int q) {
    int ans;
    cout << "? " << p << " " << q << endl;
    cin >> ans;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int R,C,K; cin >> R >> C >> K;
    int lowr = 1, highr = R+1, lowc = 1, highc = C+1;
    int ans = INT_MAX, midr, midc, val1, val2, val3;
    while(highr-lowr > 1 || highc-lowc > 1) {
        midr = (lowr+highr)/2;
        midc = (lowc+highc)/2;
        //cout << lowr << " " << highr << " " << lowc << " " << highc << "\n";
        val1 = ask(midr, midc);
        if(highr-lowr > 1) {
            if(midr == 1) {
                val2 = ask(midr+1, midc);
                if(val2-val1 < 0) lowr = midr+1;
                else highr = midr;
            } else {
                val2 = ask(midr-1, midc);
                if(val1-val2 < 0) lowr = midr+1;
                else highr = midr;
            }
            ans = min(ans, val2);
        }
        if(highc-lowc > 1) {
            if(midc == 1) {
                val3 = ask(midr, midc+1);
                if(val3-val1 < 0) lowc = midc+1;
                else highc = midc;
            } else {
                val3 = ask(midr, midc-1);
                if(val1-val3 < 0) lowc = midc+1;
                else highc = midc;
            }
            ans = min(ans, val3);
        }
        ans = min(ans, val1);
    }
    if(lowr <= R && lowc <= C) ans = min(ans, ask(lowr, lowc));
    cout << "! " << ans << endl;
    return 0;
}