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
struct tri {
    ll x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
    tri(){}
};
tri arr[3001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N, Q; cin >> N >> Q;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i].x1 >> arr[i].y1 >> arr[i].x2 >> arr[i].y2 >> arr[i].x3 >> arr[i].y3;
        assert(arr[i].x1 == arr[i].x2);
        assert(arr[i].x1 != arr[i].x3);
        assert(arr[i].y1 != arr[i].y2);
        assert(arr[i].y1 == arr[i].y3);
    }
    for(int i = 1; i <= Q; i++) {
        ll qx,qy;
        cin >> qx >> qy;
        int cnt = 0;
        for(int j = 1; j <= N; j++) {
            if(arr[j].x3 > arr[j].x1) {
                ll slopeN = (arr[j].y3-arr[j].y2);
                ll slopeD = (arr[j].x3-arr[j].x2);
                ll lineyN = arr[j].y2*slopeD+(qx-arr[j].x2)*slopeN;
                if(arr[j].y2 > arr[j].y1) {
                    if(qx >= arr[j].x1 && qx <= arr[j].x3 && qy >= arr[j].y1 && qy <= arr[j].y2) {
                        if(qy*slopeD <= lineyN) cnt++;
                    }
                } else {
                    if(qx >= arr[j].x1 && qx <= arr[j].x3 && qy <= arr[j].y1 && qy >= arr[j].y2) {
                        if(qy*slopeD >= lineyN) cnt++;
                    }
                }
            } else {
                ll slopeN = (arr[j].y2-arr[j].y3);
                ll slopeD = (arr[j].x2-arr[j].x3);
                ll lineyN = arr[j].y2*slopeD+(qx-arr[j].x2)*slopeN;
                if(arr[j].y2 > arr[j].y1) {
                    if(qx <= arr[j].x1 && qx >= arr[j].x3 && qy >= arr[j].y1 && qy <= arr[j].y2) {
                        if(qy*slopeD <= lineyN) cnt++;
                    }
                } else {
                    if(qx <= arr[j].x1 && qx >= arr[j].x3 && qy <= arr[j].y1 && qy >= arr[j].y2) {
                        if(qy*slopeD >= lineyN) cnt++;
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}