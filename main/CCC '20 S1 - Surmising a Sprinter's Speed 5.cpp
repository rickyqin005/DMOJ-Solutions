#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define pii pair<int, int>
bool comp(pii a, pii b) {
    return a.first < b.first;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    pii obs[N];
    for(int i = 0,t,x; i < N; i++) {
        cin >> t >> x;
        obs[i] = make_pair(t,x);
    }
    sort(obs, obs+N, comp);
    double ans = 0;
    for(int i = 1; i < N; i++) {
        ans = max(ans, abs(((double)obs[i].second-obs[i-1].second)/(obs[i].first-obs[i-1].first)));
    }
    printf("%.08f\n", ans);
    return 0;
}