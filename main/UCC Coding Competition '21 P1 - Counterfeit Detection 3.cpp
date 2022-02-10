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
    string str; cin >> str;
    int ans = 0;
    for(int i = 0; i < str.length()-1; i++) {
        if(str.at(i) == '2') {
            if(str.at(i+1) != '5') ans++;
        }
    }
    if(str.at(str.length()-1) == '2') ans++;
    cout << ans << endl;
    return 0;
}