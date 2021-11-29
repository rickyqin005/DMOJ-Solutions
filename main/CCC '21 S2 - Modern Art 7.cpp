#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long
#define pb push_back
int main() {
    int M, N, K; cin >> M >> N >> K;
    bool row[M+1], col[N+1];
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    char select;
    int num;
    for(int i = 0; i < K; i++) {
        cin >> select; cin >> num;
        if(select == 'R') row[num] = !row[num];
        else col[num] = !col[num];
    }
    int ans = 0;
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            if(row[i]+col[j] == 1) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}