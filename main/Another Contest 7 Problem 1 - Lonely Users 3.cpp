#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef pair<int, pii> pipii;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int i = 1,N; i <= T; i++) {
        cin >> N;
        if(N == 2) cout << 2 << "\n";
        else cout << N-1 << "\n";
    }
    return 0;
}