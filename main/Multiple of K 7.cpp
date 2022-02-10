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
typedef pair<int, pii> pipii;
int idx[10000000];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    fill(idx, idx+1000000, -1);
    idx[0] = 0;
    int N,K; cin >> N >> K;
    int curr = 0, ans = -1;
    for(int i = 1,a; i <= N; i++) {
        cin >> a;
        curr = (curr+a)%K;
        if(idx[curr%K] != -1) {
            ans = max(ans, i-idx[curr%K]);
        }
        if(idx[curr] == -1) idx[curr] = i;
    }
    cout << ans << "\n";
    //for(int i = 0; i < K; i++) {cout << idx[i] << " ";} cout << "\n";
    return 0;
}