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
int N, M; ll ans;
pii vac[MAXN+2];
pii cord[MAXN+2];
int ordCY[MAXN+2];
int bit[MAXN+2];
bool comp1(pii a, pii b) {return a.s > b.s;}
bool comp2(pii a, pii b) {return a.f < b.f;}
bool comp3(int a, int b) {return cord[a].s > cord[b].s;}
int query(int R) {
    int ans = 0;
    int pow = 1;
    while(R > 0) {
        if((R & pow) == pow) {
            ans += bit[R];
            R ^= pow;
        }
        pow <<= 1;
    }
    return ans;
}
void update(int idx, int inc) {
    while(idx <= M) {
        bit[idx] += inc;
        idx += idx & -idx;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    memset(bit, 0, sizeof(bit));
    cin >> N >> M;
    for(int i = 1,x,y; i <= N; i++) {
        cin >> x >> y;
        vac[i] = mp(x,y);
    }
    for(int i = 1,x,y; i <= M; i++) {
        cin >> x >> y;
        cord[i] = mp(x,y);
    }
    for(int i = 1; i <= M; i++) {ordCY[i] = i;}
    sort(vac+1, vac+N+1, comp1);
    sort(cord+1, cord+M+1, comp2);
    sort(ordCY+1, ordCY+M+1, comp3);

    int posC = 1, low,high,mid,bs;
    for(int i = 1; i <= N; i++) {
        while(cord[ordCY[posC]].s >= vac[i].s && posC <= M) {
            //cout << "added " << cord[ordCY[posC]].f << " " << cord[ordCY[posC]].s << "  " << ordCY[posC] << "\n";
            update(ordCY[posC], 1);
            posC++;
        }
        low = 1; high = M+1; bs = 0;
        if(vac[i].f < cord[1].f) bs = 0;
        else if(vac[i].f >= cord[M].f) bs = M;
        else {
            while(low < high) {
                mid = (low+high)/2;
                if(vac[i].f >= cord[mid].f) {
                    low = mid+1;
                    bs = max(bs, mid);
                } else {
                    high = mid;
                }
            }
        }
        //cout << "bs: " << bs << "\n";
        if(bs != 0) {
            ans += query(bs);
        }
        //for(int i = 1; i <= M; i++) {cout << bit[i] << " ";} cout << "\n";
    }
    cout << ans << "\n";
    return 0;
}