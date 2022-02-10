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
vector<int> fact;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll K; cin >> K; K++;
    int sum = 0;
    while(K%2 == 0) {
        K /= 2; fact.pb(2); sum += 1;
    }
    for(int i = 3; i <= K && i <= 100000 && sum <= 100000; i += 2) {
        while(K%i == 0) {
            K /= i; fact.pb(i); sum += i-1;
        }
    }
    if(K > 1 || sum > 100000) {cout << "Sad Chris" << "\n"; exit(0);}
    cout << sum << endl;
    for(int i = 0, cnt = 1; i < fact.size(); i++, cnt++) {
        for(int j = 1; j <= fact[i]-1; j++) cout << cnt << " ";
    }
    cout << "\n";
    return 0;
}