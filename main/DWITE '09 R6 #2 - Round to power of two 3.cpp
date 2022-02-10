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
    for(int t = 1; t <= 5; t++) {
        int N; cin >> N;
        if(N == 0) {cout << 1 << endl; continue;}
        int n = N, pow = 1;
        while(n > 0) {
            pow <<= 1; n >>= 1;
        }
        if(pow-N <= N-(pow>>1)) cout << pow << endl;
        else cout << (pow>>1) << endl;
    }
}