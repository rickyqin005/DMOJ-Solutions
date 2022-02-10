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
    cout << str[0];
    for(int i = 1; i < str.length(); i++) {
        if((str[i] == 'A') ^ (str[i-1] == 'A')) cout << str[i];
        else cout << " " << str[i];
    }
    cout << "\n";
    return 0;
}