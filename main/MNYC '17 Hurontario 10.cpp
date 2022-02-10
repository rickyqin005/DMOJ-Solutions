#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 222333555557777777
#define BASE 31
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
ll power[1000001];
string A,B;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> A >> B;
    int minLen = min(A.length(), B.length());
    power[0] = 1;
    for(int i = 1; i <= minLen; i++) power[i] = (power[i-1]*BASE)%MOD;
    ll hashA = 0, hashB = 0;
    int ans = 0;
    for(int i = 0; i < minLen; i++) {
        hashA = (hashA*BASE)%MOD;
        hashA = (hashA+(A[A.length()-1-i]-'A'))%MOD;
        hashB = (hashB+(B[i]-'A')*power[i])%MOD;
        if(hashA == hashB) ans = i+1;
    }
    //cout << ans << "\n";
    cout << A.substr(0, A.length()-ans) << B << "\n";
    return 0;
}