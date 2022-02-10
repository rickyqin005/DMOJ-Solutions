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
int idxarr[10001][27];
int dp[27];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N,K; cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        cin >> str;
        for(int j = 1; j <= K; j++) idxarr[i][str[j-1]-'A'+1] = j;
    }
    /*for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K; j++) {cout << idxarr[i][j] << " ";} cout << "\n";
    }*/
    str = "0"+str;
    dp[1] = 1;
    for(int j = 2; j <= K; j++) {
        char chr1 = str[j];
        for(int k = 1; k < j; k++) {
            char chr2 = str[k];
            bool flag = true;
            for(int i = 1; i <= N; i++) {
                if(idxarr[i][chr2-'A'+1] > idxarr[i][chr1-'A'+1]) {
                    flag = false; break;
                }
            }
            if(flag) {
                dp[j] = max(dp[j], dp[k]+1);
            }
        }
        dp[j] = max(dp[j], dp[j-1]);
    }
    cout << dp[K] << "\n";
    return 0;
}