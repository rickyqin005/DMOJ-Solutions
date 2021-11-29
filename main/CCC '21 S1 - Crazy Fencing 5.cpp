#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long
int main() {
    int N; cin >> N;
    int arr[N+1];
    for(int i = 0; i <= N; i++) {
        cin >> arr[i];
    }
    double ans = 0;
    for(int i = 0,w; i < N; i++) {
        cin >> w;
        ans += w*((double)arr[i]+arr[i+1])/2.0;
    }
    cout << fixed << setprecision(1) << ans << "\n";
    return 0;
}