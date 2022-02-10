#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int M, N, K;
vector<vector<int>>song;
int binarySearch(int col, int val) {
    if(song[0][col] > val || song[M-1][col] < val) return -1;
    int low = 0, high = M, mid = 0;
    while(low < high) {
        mid = (low+high)/2;
        if(song[mid][col] == val) return mid;
        else if(song[mid][col] > val) high = mid;
        else low = mid+1;
    }
    return -1;
}
int column = 0;
bool comp(const vector<int>& a, const vector<int>& b) {
    return a[column] < b[column];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> M >> N >> K;
    int ans = 0;
    for(int i = 0; i < M; i++) {
        song.push_back(vector<int>(N));
        for(int j = 0; j < N; j++) {
            cin >> song[i][j];
        }
    }
    for(int i = 1; i < N; i++) {
        column = i;
        sort(song.begin(), song.end(), comp);
        for(int j = 0; j < M-1; j++) {
            int bs = binarySearch(i, song[j][i]+K);
            if(bs != -1) {
                if(song[bs][i]-song[j][i] == song[bs][i-1]-song[j][i-1]) {
                    ans++;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}