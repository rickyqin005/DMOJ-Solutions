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
string str;
int posI[100001];
int gapI[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    cin >> str;
    posI[0] = 0;
    int idx = 1;
    for(int i = 0; i < 2*N; i++) {
        if(str[i] == 'I') {
            posI[idx] = i;
            idx++;
        }
    }
    for(int i = 2; i <= N; i++) gapI[i] = posI[i]-posI[i-1];
    int ans = 0;
    for(int i = 0; i < 2*N; i++) {
        if(str[i] == 'I') break;
        ans++;
    }
    if(str[2*N-1] != 'I') {
        for(int i = 2*N-2; i >= 0; i--) {
            if(str[i] == 'I') break;
            ans++;
        }
    }
    for(int i = 2; i <= N; i++) ans += max(gapI[i]-2, 0);
    cout << ans << "\n";
    return 0;
}