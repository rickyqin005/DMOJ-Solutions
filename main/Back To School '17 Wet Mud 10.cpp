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

#define MAXN 100000
#define MAXt 1000000
int mud[MAXN+1];
int dp[MAXN+1];
int freq[MAXt+1];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    memset(mud, -1, sizeof(mud));
    memset(dp, -1, sizeof(dp));
    memset(freq, 0, sizeof(freq));
    int N, M, J; cin >> N >> M >> J;
    if(J == N+1) {
        cout << 0 << "\n";
        return 0;
    }

    for(int i = 0,p,t; i < M; i++) {
        cin >> p >> t;
        mud[p] = t;
    }
    set<int> time;
    dp[0] = 0;
    time.insert(dp[0]);
    freq[dp[0]]++;

    for(int i = 1; i < J; i++) {
        if(mud[i] != -1) {
            dp[i] = max(*time.begin(), mud[i]);
            time.insert(dp[i]);
            freq[dp[i]]++;
        }
    }

    for(int i = J; i <= N; i++) {
        if(time.size() == 0) {
            cout << -1 << "\n";
            return 0;
        }
        if(mud[i] != -1) {
            dp[i] = max(*time.begin(), mud[i]);
            time.insert(dp[i]);
            freq[dp[i]]++;
        }
        if(dp[i-J] != -1) {
            freq[dp[i-J]]--;
            if(freq[dp[i-J]] == 0) {
                time.erase(dp[i-J]);
            }
        }
    }
    if(time.size() == 0) cout << -1 << "\n";
    else cout << *time.begin() << "\n";

    return 0;
}