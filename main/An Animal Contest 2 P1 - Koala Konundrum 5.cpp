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
int freq[26];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(freq, 0, sizeof(freq));
    int N; cin >> N;
    string s; cin >> s;
    for(int i = 0; i < s.length(); i++) freq[s[i]-'a']++;
    int ans = 0;
    for(int i = 0; i < 26; i++) {
        if(freq[i] > 0 && freq[i]%2 == 1) ans++;
    }
    if(ans == 0) cout << 1 << "\n";
    else cout << ans << "\n";
    return 0;
}