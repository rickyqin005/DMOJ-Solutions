#include<bits/stdc++.h>
#include<iostream>
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

#define MAXN 500
bool good1[MAXN+1][MAXN+1];
bool good2[MAXN+1][MAXN+1];
int suf[MAXN+1][MAXN+1];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int N; cin >> N;
    memset(good1, 0, sizeof(good1));
    memset(good2, 0, sizeof(good2));
    memset(suf, 0, sizeof(suf));
    for(int i = 1,n; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> n;
            good1[i][j] = n >= 100;
            good2[i][j] = n >= 101;
        }
    }
    for(int j = 1; j <= N; j++) {
        suf[N][j] = good1[N][j]?1:0;
        for(int i = N-1; i > 0; i--) {
            suf[i][j] = good1[i][j]?suf[i+1][j]+1:0;
        }
    }
    ll ans = 0;
    for(int i = 1,curr; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            curr = suf[i][j];
            ans += curr;
            for(int k = j+1; k <= N && curr > 0; k++) {
                curr = min(curr, suf[i][k]);
                ans += curr;
            }
        }
    }

    for(int j = 1; j <= N; j++) {
        suf[N][j] = good2[N][j]?1:0;
        for(int i = N-1; i > 0; i--) {
            suf[i][j] = good2[i][j]?suf[i+1][j]+1:0;
        }
    }
    for(int i = 1,curr; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            curr = suf[i][j];
            ans -= curr;
            for(int k = j+1; k <= N && curr > 0; k++) {
                curr = min(curr, suf[i][k]);
                ans -= curr;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}