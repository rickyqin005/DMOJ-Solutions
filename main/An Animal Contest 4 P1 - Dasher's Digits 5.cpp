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
int arr[1000001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N,M; cin >> N >> M;
    cin >> str;
    for(int i = 1; i <= M; i++) cin >> arr[i];
    int maxA = 0;
    int maxIdx = 0;
    for(int i = M; i >= 1; i--) {
        if(arr[i] > maxA) {
            maxA = arr[i];
            maxIdx = i;
        }
    }
    int cnt = 0,pos = 0;
    for(; pos < str.length(); pos++) {
        if(str[pos] == '0') cnt++;
        if(cnt == maxIdx) break;
    }
    for(int i = pos+1;; i++) {
        if(i == str.length()) i = 0;
        if(i == pos) break;
        if(str[i] == '0') continue;
        cout << str[i];
    }
    cout << "\n";
    return 0;
}