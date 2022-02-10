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
int arr[100001];
int dp[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    dp[1] = 1;
    int maxNum = arr[1];
    int maxIdx = 1;
    for(int i = 2; i <= N; i++) {
        if(arr[i] >= maxNum) {
            dp[i] = ((ll)dp[maxIdx]*(i-maxIdx+1))%MOD;
            maxNum = arr[i];
            maxIdx = i;
        } else {
            dp[i] = dp[i-1];
        }
    }
    //for(int i = 1; i <= N; i++) {cout << dp[i] << " ";}cout << "\n";
    cout << dp[N] << "\n";
    return 0;
}