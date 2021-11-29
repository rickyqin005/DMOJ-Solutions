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
ll gcd(ll a,ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll X,Y; cin >> X >> Y;
    cout << X*Y/gcd(max(X,Y), min(X,Y)) << "\n";
    return 0;
}