#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807
#define MAX_DOUBLE 1e18
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, double> pid;
typedef pair<double, int> pdi;
typedef pair<pii, int> piipi;
#define MAXN 300000
pii gem[MAXN+1];
int bag[MAXN+1];
class Comp {
public:
  bool operator() (pii a, pii b) {
    return a.s < b.s;
  }
};
bool comp(pii a, pii b) {
    return a.f < b.f;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    memset(gem, 0, sizeof(gem));
    memset(bag, 0, sizeof(bag));
    int N, K; cin >> N >> K;
    priority_queue<pii,vector<pii>,Comp> pq;
    for(int i = 0,m,v; i < N; i++) {
        cin >> m >> v;
        gem[i] = mp(m,v);
    }
    for(int i = 0; i < K; i++) {
        cin >> bag[i];
    }
    sort(gem, gem+N, comp);
    sort(bag, bag+K);
    ll ans = 0;
    int curr = 0;
    for(int i = 0; i < K; i++) {
        while(gem[curr].f <= bag[i] && curr < N) {
            pq.push(gem[curr]);
            curr++;
        }
        if(!pq.empty()) {
            pii next = pq.top(); pq.pop();
            ans += next.s;
        }
    }
    cout << ans << "\n";
    return 0;
}