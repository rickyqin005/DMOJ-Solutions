#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 22333555577777//2e13
#define BASE 100003
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
int freq[100001];
int freqfreq[100001];
ll power[100001];
unordered_map<ll, int> freqMap;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(freq, 0, sizeof(freq)); power[0] = 1;
    memset(freqfreq, 0, sizeof(freqfreq));
    int N,M; cin >> N >> M;
    freqfreq[0] = M;
    freqMap[0] = 1;
    for(int i = 1; i <= M; i++) power[i] = (power[i-1]*BASE)%MOD;
    ll sumPow = 0;
    for(int i = 1; i <= M; i++) sumPow = (sumPow+power[i])%MOD;

    int minFreq = 0;
    ll freqHash = 0;
    ll ans = 0;
    for(int i = 1,a; i <= N; i++) {
        cin >> a;
        freqfreq[freq[a]]--;
        freq[a]++;
        freqfreq[freq[a]]++;

        freqHash = (freqHash+power[a])%MOD;
        //cout << freqHash << "\n";

        if(freqfreq[minFreq] == 0) {
            minFreq++;
            freqHash = (freqHash-sumPow+MOD)%MOD;
        }
        //for(int j = 1; j <= M; j++) {cout << freq[j]-minFreq << " ";} cout << "\n";

        ans += freqMap[freqHash];
        freqMap[freqHash]++;
    }
    cout << ans << "\n";
    return 0;
}
