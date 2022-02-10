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
int a[4010];
int freq[4010];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(a, 0, sizeof(a));
    memset(freq, 0, sizeof(freq));
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> a[i];
    sort(a+1, a+N+1);

    for(int i = 1,pos; i <= N; i = pos) {
        pos = i;
        for(; pos <= N; pos++) {
            if(a[pos] != a[i]) break;
        }
        for(int j = i; j < pos && j <= N; j++) freq[j] = (pos-i);
    }
    //for(int i = 1; i <= N; i++) {cout << freq[i] << " ";}cout << "\n";
    int ans = 1;
    for(int i = 2,pos; i < N; i++) {
        pos = i+1;
        for(int j = i-1; j >= 1; j--) {
            if(a[j] == a[i]) continue;
            while(pos <= N && a[pos]+a[j] < 2*a[i]) pos++;
            if(pos <= N && a[pos]+a[j] == 2*a[i]) ans = max(ans, freq[i]+2);
        }
    }
    for(int i = 3,pos; i <= N; i++) {
        pos = 1;
        for(int j = i-1; j >= 1 && j > pos; j--) {
            while(pos <= N && pos < j && a[pos]+a[j] < a[i]) pos++;
            if(pos <= N && pos < j && a[pos]+a[j] == a[i]) ans = max(ans, freq[i]+1);
        }
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = i+1; j <= N; j++) {
            if((a[i]+a[j])%2 == 0) ans = max(ans, 2);
        }
    }
    for(int i = 1; i <= N; i++) ans = max(ans, freq[i]);
    cout << ans << "\n";
    return 0;
}