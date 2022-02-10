#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;
pii arr[400000];
bool comp(pii a, pii b) {return a.f < b.f;}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    ll currY = 0, currM = 0, ans = MAX_LONG; int idx = 0, pos = 0;
    for(int i = 0,p,w,d; i < N; i++) {
        cin >> p >> w >> d;
        arr[2*i] = mp(p-d, w);
        arr[2*i+1] = mp(p+d, w);
        currY += max((ll)w*(abs(0-p)-d),0LL);
        if(p-d > 0) currM -= w;
        else if(p == 0 && d == 0) currM += w;
    }
    ans = min(ans, currY);
    //cout << currY << " " << currM << "\n\n";
    sort(arr, arr+2*N, comp);
    while(idx < 2*N && arr[idx].f <= 0) idx++;
    for(; idx < 2*N; idx++) {
        //cout << arr[idx].f << " " << arr[idx].s << "\n";
        currY += currM*(arr[idx].f-pos);
        currM += arr[idx].s;
        pos = arr[idx].f;
        //cout << currY << " " << currM << "\n\n";
        ans = min(ans, currY);
    }
    cout << ans << "\n";
    return 0;
}