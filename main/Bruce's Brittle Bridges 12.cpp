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
#define MAXN 200000
int N;
int v[MAXN+1];
vector<pii> adj[MAXN+1];
pll dfs1(int curr, int prev) {
    ll sum = v[curr];
    ll max1 = 0;
    for(pii next: adj[curr]) {
        if(next.f == prev) continue;
        pll val = dfs1(next.f, curr);
        if(next.s >= 2) sum += val.f;
        else max1 = max(max1, val.f+val.s);
        max1 = max(max1, val.s);
    }
    return mp(sum,max1);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++) {cin >> v[i];}
    for(int i = 1,a,b,t; i < N; i++) {
        cin >> a >> b >> t;
        adj[a].pb(mp(b,t));
        adj[b].pb(mp(a,t));
    }
    pll ans = dfs1(1,-1);
    cout << ans.f+ans.s << "\n";
    return 0;
}