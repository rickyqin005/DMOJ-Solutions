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
ll R,C; int M;
set<int> row;
set<int> col;
int pane[5][1001];
ll arr[2001][2002];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(pane, 0, sizeof(pane));
    int N,T; cin >> N >> T;
    for(int i = 1; i <= N; i++) {
        cin >> pane[1][i] >> pane[0][i] >> pane[3][i] >> pane[2][i] >> pane[4][i];
        row.insert(pane[0][i]);
        row.insert(pane[2][i]);
        col.insert(pane[1][i]);
        col.insert(pane[3][i]);
    }
    int ri,ci; bool b1,b2;
    for(int i = 1; i <= N; i++) {
        ci = 1; b1 = false; b2 = false;
        for(int j: col) {
            if(b1 && b2) break;
            if(j > pane[1][i] && !b1) {
                ri = 1;
                for(int k: row) {
                    if(k > pane[2][i]) break;
                    if(k > pane[0][i]) {
                        arr[ri][ci] += pane[4][i];
                    }
                    ri++;
                }
                b1 = true;
            } else if(j > pane[3][i] && !b2) {
                ri = 1;
                for(int k: row) {
                    if(k > pane[2][i]) break;
                    if(k > pane[0][i]) {
                        arr[ri][ci] += -pane[4][i];
                    }
                    ri++;
                }
                b2 = true;
            }
            ci++;
        }
    }
    ll ans = 0;
    int prevR = 0, prevC; ri = 1;
    for(int i: row) {
        ci = 1;
        for(int j: col) {
            arr[ri][ci] += arr[ri][ci-1];
            if(arr[ri][ci] >= T) {
                ans += ((ll)j-prevC)*(i-prevR);
            }
            prevC = j;
            ci++;
        }
        prevR = i;
        ri++;
    }
    cout << ans << "\n";
    return 0;
}