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
ll arr[100001];
ll pfs[100001];
ll sum(int l, int r) {return ((l <= r)?pfs[r]-pfs[l-1]:0);}
ll cost(int l, int r) {
    return arr[(l+r)/2]*((l+r)/2-l+1)-sum(l,(l+r)/2) + sum((l+r)/2, r)-arr[(l+r)/2]*(r-(l+r)/2+1);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(arr, 0, sizeof(arr));
    memset(pfs, 0, sizeof(pfs));
    int R,L; ll B; cin >> R >> L >> B;
    for(int i = 1; i <= R; i++) {
        cin >> arr[i];
        pfs[i] = arr[i]+pfs[i-1];
    }
    int ans = 0;
    for(int i = 1; i <= R; i++) {
        int low = i, high = R+1, mid, maxPos = low; ll val;
        while(low < high) {
            mid = (low+high)/2;
            val = cost(i,mid);
            if(val <= B) {
                maxPos = max(maxPos, mid);
                low = mid+1;
            } else {
                high = mid;
            }
        }
        ans = max(ans, maxPos-i+1);
    }
    cout << ans << "\n";
    return 0;
}
