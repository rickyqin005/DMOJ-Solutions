#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define f first
#define s second
typedef pair<int, int> pii;
typedef long long ll;
int arr[200000];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N,D,K; cin >> N >> D >> K;
    for(int i = 0; i < N; i++) {cin >> arr[i];}
    sort(arr, arr+N, greater<int>());
    ll ans = 0;
    for(int i = K; i < N; i++) {
        ans += ceil((double)arr[i]/D);
    }
    cout << ans << "\n";
    return 0;
}