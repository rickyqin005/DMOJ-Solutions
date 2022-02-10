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
vii cnt[31][31];
bool temp[31][31];
bool vis[31][31];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(vis, 0, sizeof(vis));
    int N, M, S; cin >> N >> M >> S;
    string str;
    for(int i = 1; i <= N; i++) {
        cin >> str;
        memset(temp, 0, sizeof(temp));
        for(int j = S; j > 0; j--) {
            temp[j][j] = 1;
            for(int k = j+1; k <= S; k++) {
                if(str[j-1] == str[k-1]) {
                    if(k-j == 1) temp[j][k] = 1;
                    else temp[j][k] = temp[j+1][k-1];
                }
            }
        }
        for(int j = 1; j <= S; j++) {
            for(int k = 1; k <= S; k++) {
               if(temp[j][k]) cnt[j][k].pb(i);
            }
        }
    }
    bool arr1[N+1];
    bool arr2[N+1];
    memset(arr1, 1, sizeof(arr1));
    for(int i = 0,l,r; i < M; i++) {
        cin >> l >> r;
        if(vis[l][r]) continue;
        vis[l][r] = true;
        memset(arr2, 0, sizeof(arr2));
        for(int j: cnt[l][r]) {
            arr2[j] = arr1[j];
        }
        for(int j = 1; j <= N; j++) {arr1[j] = arr2[j];}
    }
    int ans = 0;
    for(int i = 1; i <= N; i++) {ans += arr1[i];}
    cout << ans << "\n";
    return 0;
}