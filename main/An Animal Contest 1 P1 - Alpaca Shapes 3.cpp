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
typedef pair<int, pii> pipii;
#define PI 3.1415926535897
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int S,R; cin >> S >> R;
    cout << ((S*S>PI*R*R)?"SQUARE":"CIRCLE") << "\n";
    return 0;
}