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
pii freq[1001];
bool comp(pii a, pii b) {
    return ((a.f == b.f) ? (a.s < b.s) : (a.f > b.f));
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i = 1; i <= 1000; i++) freq[i] = mp(0, i);
    int N; cin >> N;
    for(int i = 1,r; i <= N; i++) {
        cin >> r;
        freq[r].f++;
    }
    sort(freq+1, freq+1000+1, comp);
    int L1 = 1, R1 = 2;// [L1, R1)
    while(R1 <= 1000 && freq[R1].f == freq[L1].f) R1++;
    int L2 = R1, R2 = L2+1;// [L2, R2)
    while(R2 <= 1000 && freq[R2].f == freq[L2].f) R2++;
    if(R1-L1 > 1) {
        cout << freq[R1-1].s-freq[L1].s << "\n";
    } else {
        cout << max(abs(freq[L1].s-freq[L2].s), abs(freq[L1].s-freq[R2-1].s)) << "\n";
    }
    return 0;
}
