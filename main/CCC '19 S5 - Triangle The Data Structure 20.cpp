#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef pair<int, pii> pipii;
int N,K;
int arr[3001][3001];
int bit[3001][3001];
int query(int R, int C) {
    int ans = 0;
    for(int r = R; r >= R-K+1 && r > 0; r -= r&-r) {
        for(int c = C; c >= C-K+1 && c > 0; c -= c&-c) {ans = max(ans, bit[r][c]);}
    }
    return ans;
}
void update(int R, int C, int val) {
    for(int r = R; r <= R+K-1 && r <= N; r += r&-r) {
        for(int c = C; c <= C+K-1 && c <= N; c += c&-c) {bit[r][c] = max(bit[r][c], val);}
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(bit, 0, sizeof(bit));
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        for(int j = N-i+1; j <= N; j++) {cin >> arr[i][j];}
    }
    for(int i = K-1; i >= 1; i--) {
        for(int j = i; j >= 1; j--) {
            update(N-(K-1)+i, N-j+1, arr[N-(K-1)+i][N-j+1]);
        }
    }
    ll ans = 0;
    for(int i = K; i <= N; i++) {
        for(int r = N, c = N-i+1; c <= N; r--, c++) {
            update(r,c,arr[r][c]);
        }
        for(int r = N, c = N-i+K; c <= N; r--, c++) {
            ans += query(r,c);
        }
    }
    cout << ans << endl;
    return 0;
}