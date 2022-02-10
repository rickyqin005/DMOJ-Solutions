#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
int diff[1001][30002];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(diff, 0, sizeof(diff));
    int M, N, K; cin >> M >> N >> K;
    for(int i = 1,n,m,r,b,r2,d; i <= K; i++) {
        cin >> n >> m >> r >> b;
        r2 = r*r;
        for(int j = max(-r,-n+1); j <= r; j++) {
            if(n+j > N) break;
            d = (int)sqrt(r2-j*j);
            diff[n+j][max(m-d,1)] += b;
            diff[n+j][min(m+d,M)+1] += -b;
        }
    }
    int maxb = 0, maxn = 0;
    for(int i = 1,curr; i <= N; i++) {
        curr = 0;
        for(int j = 1; j <= M; j++) {
            curr += diff[i][j];
            if(curr > maxb) {
                maxb = curr;
                maxn = 1;
            } else if(curr == maxb) {
                maxn++;
            }
        }
    }
    cout << maxb << "\n" << maxn << "\n";
    return 0;
}