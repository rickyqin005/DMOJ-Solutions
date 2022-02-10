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
int N,K,ans = 0x7f7f7f7f;
string str;
int freq[4096];
void recurse(int pos, int state) {
    int maxWrong = 0;
    if(pos == K) {
        for(int i = 0; i < (1<<K); i++) {
            if(freq[i] > 0) maxWrong = max(maxWrong, (int)bitset<32>(i^state).count());
        }
        ans = min(ans, maxWrong);
    } else {
        recurse(pos+1, state);
        recurse(pos+1, state+(1<<pos));
    }
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(freq, 0, sizeof(freq));
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        cin >> str;
        int idx = 0;
        for(int j = 0; j < str.length(); j++) {
            idx += ((str[j] == 'T')?(1<<j):0);
        }
        freq[idx]++;
    }
    recurse(0, 0);
    cout << K-ans << "\n";
    return 0;
}