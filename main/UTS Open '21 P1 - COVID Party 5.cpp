#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int N; cin >> N;
    if(N == 2) {cout << 1 << "\n"; return 0;}
    int S = 2;
    int amt = 2;
    int inc = 3;
    while(true) {
        amt = amt + inc;
        if(amt >= N) break;
        if((S % 2) == 1) inc = inc + 2;
        S++;
        //cout << amt << "\n";
    }
    cout << S << "\n";
    return 0;
}