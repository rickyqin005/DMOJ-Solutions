#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    int cow[N], stall[N];
    for(int i = 0; i < N; i++) cin >> cow[i];
    for(int i = 0; i < N; i++) cin >> stall[i];
    sort(cow, cow+N, greater<int>());

    ll ans = 1;
    for(int i = 0; i < N; i++) {
        int curr = 0;
        for(int j = 0; j < N; j++) {
            if(stall[j] >= cow[i]) curr++;
        }
        ans *= curr-i;
    }
    cout << ans << "\n";
    return 0;
}