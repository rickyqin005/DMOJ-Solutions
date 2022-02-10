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
ll speed [1000002];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(speed, 0, sizeof(speed));
    int N,K; ll D,X; cin >> N >> D >> K >> X;
    for(int i = 1; i <= N; i++) {cin >> speed[i];}
    ll P; cin >> P;
    sort(speed+1, speed+N+1, greater<ll>());
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        if(cnt >= K) break;
        while(speed[i] >= P && cnt < K) {
            speed[i] = speed[i]*(100-X)/100;
            cnt++;
        }
    }
    ll maxs = 0;
    for(int i = 1; i <= N; i++) {maxs = max(maxs, speed[i]);}
    if(P > maxs) cout << "YES" << "\n";
    else cout << "NO" << "\n";
    return 0;
}