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
const int MAXN = 100000;
int N;
bool p[100001];
bool vis[100001];
bool dp[100001];
vector<int> prime;
//turn: 0 -> loss, 1 -> win
bool solve(int num) {
    if(num == 1 || num == 2) return 0;
    if(vis[num]) return dp[num];
    for(int p: prime) {
        if(num-p < 1) continue;
        dp[num] = (dp[num] || (!solve(num-p)));
    }
    vis[num] = true;
    return dp[num];
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(vis, 0, sizeof(vis));
    memset(dp, 0, sizeof(dp));
    memset(p, 0, sizeof(p));
    int sqr = (int)sqrt(MAXN);
    for(int i = 4; i <= MAXN; i += 2) p[i] = 1;
    for(int i = 3; i <= sqr; i += 2) {
        if(p[i]) continue;
        for(int j = i*i; j <= MAXN; j += i) p[j] = 1;
    }
    for(int i = 2; i <= MAXN; i++) {
        if(!p[i]) prime.pb(i);
    }
    reverse(prime.begin(), prime.end());
    for(int i = 1; i <= MAXN; i++) solve(i);
    //for(int i = 1; i <= 100; i++) {cout << dp[i] << " ";} cout << "\n";
    int T; cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> N;
        if(N <= 2) {cout << -1 << "\n"; continue;}
        int near;
        for(int i = N; i >= 2; i--) {
            if(dp[i]) {
                near = i; break;
            }
        }
        //cout << near << "\n";
        if(N-near == 0) {
            cout << 1;
            for(int i = 2; i <= N; i++) {cout << " " << i;} cout << "\n";
        } else {
            cout << 1;
            for(int i = 2; i < near; i++) {cout << " " << i;}
            cout << " " << N;
            for(int i = near+1; i <= N; i++) {cout << " " << i-1;}
            cout << "\n";
        }
    }
    return 0;
}