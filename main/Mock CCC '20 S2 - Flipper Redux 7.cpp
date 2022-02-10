#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define MAXN 2000
int arr[MAXN+1][MAXN+1];
vector<pii> vect;
int main() {
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    int M = 0;
    for(int j = 2; j <= N; j++) {
        if(arr[1][j] != arr[1][1]) {
            vect.pb(mp(1,j));
            M++;
        }
    }
    if(arr[1][1] == 1) {
        vect.pb(mp(0,1));
        M++;
    }
    for(int i = 2, rowState; i <= N; i++) {
        rowState = arr[i][1] == arr[1][1];
        for(int j = 2; j <= N; j++) {
            if((arr[i][j] == arr[1][j]) != rowState) {
                cout << -1 << "\n";
                return 0;
            }
        }
        if(arr[i][1] == 1) {
            vect.pb(mp(0,i));
            M++;
        }
    }
    cout << M << "\n";
    for(pii i: vect) {
        cout << (i.first == 0?"R":"C") << " " << i.second << "\n";
    }
}