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
int freq[2001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(freq, 0, sizeof(freq));
    int N; cin >> N;
    for(int i = 1,a; i <= N; i++) {
        cin >> a;
        freq[a]++;
    }
    int maxLen = 0;
    int maxLenFreq = 0;
    for(int i = 2; i <= 4000; i++) {
        int len = 0;
        for(int a = 1,b = i-a; a <= b; a++,b--) {
            if(b > 2000) continue;
            if(a == b) len += freq[a]/2;
            else len += min(freq[a], freq[b]);
        }
        if(len > maxLen) {
            maxLen = len;
            maxLenFreq = 1;
        } else if(len == maxLen) maxLenFreq++;
    }
    cout << maxLen << " " << maxLenFreq << "\n";
    return 0;
}