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
    double N,M; cin >> N >> M;
    int K = 0;
    for(int i = 1,l,r; i <= N; i++) {
        l = (int)((i-1)*M/N);
        r = (int)ceil(i*M/N);
        K += r-l;
    }
    cout << K << endl;
    for(int i = 1,l,r; i <= N; i++) {
        l = (int)((i-1)*M/N)+1;
        r = (int)ceil(i*M/N);
        for(int j = l; j <= r; j++) cout << i << " " << j << endl;
    }
    return 0;
}