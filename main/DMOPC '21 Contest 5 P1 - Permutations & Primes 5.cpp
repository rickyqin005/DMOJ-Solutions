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

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N; cin >> N;
    if(N == 1) {cout << 1 << "\n"; exit(0);}
    if(2 <= N && N <= 4) {cout << -1 << "\n"; exit(0);}
    int EVEN = 4, ODD = 5;
    int cnt = 1;
    for(int i = 2; i <= N; i+=2) {
        if(i == EVEN) continue;
        cout << i << " ";
        cnt++;
    }
    cout << EVEN << " "; cnt++;
    cout << ODD << " "; cnt++;
    for(int i = 1; i <= N; i+=2) {
        if(i == ODD) continue;
        cout << i;
        cnt++;
        if(cnt != N+1) cout << " ";
    }
    cout << "\n";
    return 0;
}