#include <bits/stdc++.h>
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
typedef pair<pii, int> piipi;
typedef vector<int> vii;
typedef vector<ll> vll;
#define MAXN 500
int B[MAXN+2];
int P[MAXN+2];
int dp[2][MAXN+2];
int main() {
	int N, M, K; cin >> N >> M >> K;
	for(int i = 1; i <= N; i++) cin >> P[i];
	for(int i = 0; i <= M; i++) cin >> B[i];
	for(int i = 1; i <= N; i++) {
		for(int j = 0; j <= K; j++) {
			for(int k = P[i]; k <= M && k-P[i] <= j; k++) {
				dp[i%2][j-(k-P[i])] = max(dp[i%2][j-(k-P[i])], dp[(i-1)%2][j]+B[k]);
			}
		}
		//for(int j = 0; j <= 50; j++) {cout << dp[i%2][j] << " ";} cout << "\n";
	}
	cout << dp[N%2][0] << "\n";
}