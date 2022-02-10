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
    int N, K; cin >> N >> K;
    for(int i = 0,S,T,R,b; i < K; i++) {
        cin >> S >> T >> R;
        b = N/(S*T);
        cout << ((N%(S*T) == 0)?(b*T+max(0,b-1)*R):(b*T+b*R+ceil((double)(N%(S*T))/S))) << "\n";
    }
    return 0;
}