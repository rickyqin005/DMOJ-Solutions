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
int A[5001];
int B[5001];
int C[5001];
int D[5001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N,K,Q; cin >> N >> K >> Q;
    for(int i = 1; i <= K; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];
    pii rc;
    for(int i = 1; i <= Q; i++) {
        cin >> rc.f >> rc.s;
        for(int j = K; j >= 1; j--) {
            if(A[j] <= rc.f && rc.f <= C[j] && B[j] <= rc.s && rc.s <= D[j]) {
                rc = mp(C[j]-(rc.s-B[j]), B[j]+(rc.f-A[j]));
            }
        }
        cout << ((ll)rc.f-1)*N+rc.s << "\n";
    }
    return 0;
}