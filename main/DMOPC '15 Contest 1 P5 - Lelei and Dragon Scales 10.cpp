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

#define MAXH 250
int arr[MAXH+1][MAXH+1];
int sum(int r1, int c1, int r2, int c2) {
    return arr[r2][c2]-arr[r1-1][c2]-arr[r2][c1-1]+arr[r1-1][c1-1];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    memset(arr, 0, sizeof(arr));
    int C, R, N; cin >> C >> R >> N;
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            arr[i][j] += arr[i][j-1];
        }
    }
    for(int j = 1; j <= C; j++) {
        for(int i = 1; i <= R; i++) {
            arr[i][j] += arr[i-1][j];
        }
    }
    int ans = 0;
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            for(int k = j; k <= C; k++) {
                ans = max(ans, sum(i,j,min(i+N/(k-j+1)-1,R),k));
            }
        }
    }
    cout << ans << "\n";
    return 0;
}