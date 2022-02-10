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
typedef pair<pii, pii> piipii;
typedef pair<int, pii> pipii;
#define MAXa 100000
vector<int> fact[100001];
int last[100001];
int arr[1000001];
piipii q[50001];
bool ans[50001];
bool comp(piipii a, piipii b) {return a.f.s < b.f.s;}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(ans, 0, sizeof(ans));
    memset(last, 0, sizeof(last));
    int N,Q; cin >> N >> Q;
    int sqra = (int)sqrt(MAXa);
    for(int i = 2; i <= sqra; i++) {
        for(int j = i*(i+1); j <= MAXa; j += i) {fact[j].pb(i);}
    }

    for(int i = 1; i <= N; i++) {cin >> arr[i];}
    for(int i = 1; i <= Q; i++) {cin >> q[i].f.f >> q[i].f.s >> q[i].s.f; q[i].s.s = i;}
    sort(q+1, q+Q+1, comp);
    int posr = 1;
    for(int i = 1,l,r,x; i <= Q; i++) {
        l = q[i].f.f; r = q[i].f.s; x = q[i].s.f;
        while(posr <= r) {
            last[arr[posr]] = posr;
            posr++;
        }
        if(x == 1) continue;
        if(last[1] >= l && last[x] >= l) {
            ans[q[i].s.s] = 1; continue;
        }
        for(int j: fact[x]) {
            if(last[j] >= l && last[x/j] >= l) {
                ans[q[i].s.s] = 1; break;
            }
        }
    }
    for(int i = 1; i <= Q; i++) {
        if(ans[i]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}