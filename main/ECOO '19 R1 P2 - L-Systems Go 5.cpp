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
string arr[26];
int adj[26][26];
ll ans[2][26];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int R,T,len; ll sum; string A,S;char c,first,last;
    for(int t = 1; t <= 10; t++) {
        memset(arr, 0, sizeof(arr));
        memset(adj, 0, sizeof(adj));
        memset(ans, 0, sizeof(ans));
        cin >> R >> T >> A;
        len = A.length();
        for(int i = 1; i <= R; i++) {
            cin >> c >> S; arr[c-65] = S;
            for(int j = 0; j < S.length(); j++) {
                adj[c-65][S.at(j)-65]++;
            }
        }
        for(int i = 0; i < 26; i++) {
            if(arr[i] == "") {
                arr[i] = (char)(i+65);
                adj[i][i]++;
            }
        }
        for(int i = 0; i < len; i++) {
            ans[0][A.at(i)-65]++;
        }
        first = A.front(); last = A.back();
        for(int i = 1; i <= T; i++) {
            first = arr[first-65].front();
            last = arr[last-65].back();
            memset(ans[i%2], 0, sizeof(ans[i%2]));
            for(int j = 0; j < 26; j++) {
                //if(ans[(i-1)%2][j] == 0) continue;
                for(int k = 0; k < 26; k++) {
                    ans[i%2][k] += adj[j][k]*ans[(i-1)%2][j];
                }
            }
            //for(int j = 0; j < 26; j++) {cout << ans[i%2][j] << " ";}cout << "\n";
        }
        sum = 0;
        for(int i = 0; i < 26; i++) {sum += ans[T%2][i];}
        cout << first << last << " " << sum << endl;
    }
    return 0;
}