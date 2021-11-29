#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
int arr[1000001];
int freq[1000001];
bool inc(int a) {
    freq[a]++;
    if(freq[a] == 1) return true;
    return false;
}
bool dec(int a) {
    freq[a]--;
    if(freq[a] == 0) return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(freq, 0, sizeof(freq));
    int N,K; cin >> N >> K;
    for(int i = 1; i <= N; i++) {cin >> arr[i];}
    int pos, cnt = 0;
    for(pos = 1; pos <= N; pos++) {
        if(inc(arr[pos])) cnt++;
        if(cnt == K) break;
    }
    if(cnt < K) {
        cout << 0 << "\n"; return 0;
    }
    ll ans = N-pos+1;
    for(int i = 2; i <= N; i++) {
        if(dec(arr[i-1])) cnt--;
        if(cnt < K) {
            for(pos++; pos <= N; pos++) {
                if(inc(arr[pos])) cnt++;
                if(cnt == K) break;
            }
            if(cnt < K) {
                cout << ans << "\n"; return 0;
            }
        }
        ans += N-pos+1;
    }
    cout << ans << "\n";
    return 0;
}