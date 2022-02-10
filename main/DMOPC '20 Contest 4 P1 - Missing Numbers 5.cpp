#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807
#define MAX_DOUBLE 1e18
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, double> pid;
typedef pair<double, int> pdi;
typedef pair<pii, int> piipi;
typedef vector<int> vii;
typedef vector<ll> vll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int T; cin >> T;
    ll diff, N, S, a, b;
    for(int i = 0; i < T; i++) {
        cin >> N >> S;
        diff = N*(N+1)/2-S;
        a = 1;
        b = diff-1;
        if(b > N) {
            a += b-N;
            b -= b-N;
        }
        cout << (b-a+1)/2 << "\n";
    }
    return 0;
}