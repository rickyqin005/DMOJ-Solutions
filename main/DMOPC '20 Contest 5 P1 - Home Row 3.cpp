#include <bits/stdc++.h>
#include <iostream>
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
    string s,t; cin >> s >> t;
    int ans = 0;
    for(int i = 0; i < min(s.length(), t.length()); i++) {
        if(s[i] != t[i]) break;
        ans++;
    }
    cout << (s.length()-ans)+(t.length()-ans) << endl;
    return 0;
}