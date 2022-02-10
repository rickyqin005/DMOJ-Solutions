#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 9999999900000001
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
int arr[200001];
int freq[200001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    int sqrtN = sqrt(N);
    int ans = N;
    for(int i = 2; i <= sqrtN; i++) {
        memset(freq, 0, sizeof(freq));
        int numGood = 0;
        for(int j = 1; j < i*i; j++) {
            freq[arr[j]]++;
            if(freq[arr[j]] == i) numGood++;
        }
        for(int j = i*i; j <= N; j++) {
            freq[arr[j]]++;
            if(freq[arr[j]] == i) numGood++;

            if(numGood == i) ans++;

            if(freq[arr[j-i*i+1]] == i) numGood--;
            freq[arr[j-i*i+1]]--;
        }
    }
    cout << ans << "\n";
    return 0;
}