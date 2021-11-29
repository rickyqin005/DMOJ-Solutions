#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;
pii arr[100001];
bool comp(pii a, pii b) {
    if(a.f == b.f) return a.s > b.s;
    return a.f < b.f;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N,M; cin >> N >> M;
    for(int i = 1,r,c; i <= M; i++) {
        cin >> r >> c;
        arr[i].f = r-c+1;
        arr[i].s = c;
    }
    sort(arr+1, arr+M+1, comp);
    //for(int i = 1; i <= M; i++) cout << arr[i].f << " " << arr[i].s << "\n";
    ll ans = 0;
    int currR = arr[1].f, currC = arr[1].s;
    for(int i = 2; i <= M; i++) {
        if(arr[i].f != currR) {
            int width1 = N-currR+1-currC+1;
            int width2 = max(N-arr[i].f+2-currC+1, 1);
            ans += (ll)(width1+width2)*min(arr[i].f-currR, width1)/2;
            //cout << (width1+width2)*min(arr[i].f-currR, width1)/2 << "\n";
            currR = arr[i].f;
        }
        currC = min(currC, arr[i].s);
    }
    ans += ((ll)(N-currR+1-currC+1)+(1))*(N-currR+1-currC+1)/2;
    cout << ans << "\n";
    return 0;
}