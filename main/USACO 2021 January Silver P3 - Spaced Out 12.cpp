#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    int grid[N][N];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    int oddRows[N] = {0}, evenRows[N] = {0};
    for(int j = 0; j < N; j++) {
        for(int i = 0; i < N; i++) {
            if(i % 2 == 0) evenRows[j] += grid[i][j];
            else oddRows[j] += grid[i][j];
        }
    }
    int oddCols[N] = {0}, evenCols[N] = {0};
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(j % 2 == 0) evenCols[i] += grid[i][j];
            else oddCols[i] += grid[i][j];
        }
    }
    int maxRows = 0;
    for(int i = 0; i < N; i++) {
        maxRows += max(oddRows[i], evenRows[i]);
    }
    int maxCols = 0;
    for(int i = 0; i < N; i++) {
        maxCols += max(oddCols[i], evenCols[i]);
    }
    cout << max(maxRows, maxCols) << "\n";
    return 0;
}