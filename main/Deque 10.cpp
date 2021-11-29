#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
int arr[3001];
ll dp[3001][3001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        dp[i][i] = arr[i];
    }
    for(int i = 1; i < N; i++) {
		for(int j = 1; j+i <= N; j++) {
			dp[j][j+i] = max(arr[j]-dp[j+1][j+i], arr[j+i]-dp[j][j+i-1]);
		}
	}
	cout << dp[1][N] << "\n";
    return 0;
}