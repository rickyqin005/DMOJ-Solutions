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

#define MAXN 10000
vector<pii> fuel;
bool comp(pii a, pii b) {
    return a.second < b.second;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int N, P; cin >> N >> P;
    int curr = 0;
    int cnt = 1;
    for(int i = 1,a,b; i <= N; i++) {
        cin >> a >> b;
        if(i == P) {
            curr += a;
            continue;
        }
        if(a >= b) fuel.pb(mp(a,b));
    }
    sort(fuel.begin(), fuel.end(), comp);
    for(pii i: fuel) {
        if(curr - i.second < 0) break;
        curr += i.first-i.second;
        cnt++;
    }
    cout << curr << "\n";
    cout << cnt << "\n";
    return 0;
}