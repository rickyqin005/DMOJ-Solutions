#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807
#define MAX_DOUBLE 1e18
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, double> pid;
typedef pair<double, int> pdi;
typedef pair<pii, int> piipi;
typedef vector<int> vii;
typedef vector<ll> vll;

#define MAXN 1000000
int dp[MAXN+1];
int loc[MAXN+1];
int len;
int bs(int val) {
    if(dp[1] > val) return 1;
    if(dp[len] < val) return len+1;
    int low = 1, high = len+1, mid, ans = INT_MAX;
    while(low < high) {
        mid = (low+high)/2;
        if(dp[mid] > val) {
            high = mid;
            ans = min(ans, mid);
        } else {
            low = mid+1;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    memset(dp, 0, sizeof(dp));
    memset(loc, 0, sizeof(loc));
    int N1; cin >> N1;
    int I;
    for(int i = 1; i <= N1; i++) {
        cin >> I;
        loc[I] = i;
    }
    int N2; cin >> N2;
    len = 0;
    dp[1] = INT_MAX;
    for(int i = 1; i <= N2; i++) {
        cin >> I;
        if(loc[I] == 0) continue;
        int idx = bs(loc[I]);
        if(idx == len+1) {
            len++;
        }
        dp[idx] = loc[I];
    }
    cout << len << "\n";
    return 0;
}
