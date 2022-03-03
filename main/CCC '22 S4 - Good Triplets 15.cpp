#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
int psa[1000001];
int sum(int l, int r) {return (l<=r ? psa[r]-psa[l-1] : 0);}
int sum(int idx) {return sum(idx, idx);}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(psa, 0, sizeof(psa));
    int N,C; cin >> N >> C;
    for(int i = 1,a; i <= N; i++) {
        cin >> a; a++;
        psa[a]++;
    }
    for(int i = 1; i <= C; i++) psa[i] += psa[i-1];
    ll ans = 0;
    ll currNum = 0;
    int start = (C%2 ? 2 : 3), last = 1+(C-1)/2;
    int thirdstart = 1+C-(C-1)/2;
    for(int i = start; i <= last; i++) currNum += (ll)sum(i)*sum(thirdstart, i + (C-1)/2);
    for(int i = 1; thirdstart+i-1 <= C; i++) {
        ans += (ll)sum(i)*currNum;
        currNum -= (ll)sum(thirdstart +i-1)*sum(start +i-1, last +i-1);
        currNum += (ll)sum(last+i)*sum(thirdstart+i, min(thirdstart+i +(last-start+1)-1, C));
    }
    cout << ans << "\n";
    return 0;
}