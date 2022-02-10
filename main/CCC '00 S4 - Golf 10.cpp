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
typedef pair<int, double> pid;
typedef pair<double, int> pdi;
typedef pair<pii, int> piipi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef unordered_set<int> u_si;
typedef unordered_map<string, int> u_msi;

#define MAXNA 490000

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int D, C; cin >> D >> C;
    int dp[D+1];
    fill_n(dp, D+1, MAX_INT);
    dp[0] = 0;
    for(int i = 0,d; i < C; i++) {
        cin >> d;
        for(int j = 0; j <= D-d; j++) {
            if(dp[j] != MAX_INT) {
                dp[j+d] = min(dp[j+d], dp[j]+1);
            }
        }
    }
    if(dp[D] == MAX_INT) cout << "Roberta acknowledges defeat." << "\n";
    else cout << "Roberta wins in " << dp[D] << " strokes." << "\n";
    return 0;
}