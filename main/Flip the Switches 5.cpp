#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long
#define pb push_back
int main() {
    int N; cin >> N;
    string str; cin >> str;
    bool state = false;
    int ans = 0;
    for(int i = N-1; i >= 0; i--) {
        if(str[i] == '1' && !state) {
            ans++;
            state = !state;
        } else if(str[i] == '0' && state) {
            ans++;
            state = !state;
        }
    }
    cout << ans << "\n";
}