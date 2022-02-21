#include <bits/stdc++.h>
using namespace std;
string str;
int main() {
    int D; cin >> D;
    cin >> str;
    for(int i = 1; i < str.length(); i++) {
        if(str[i] > str[i-1]) {
            swap(str[i], str[i-1]); break;
        }
    }
    cout << str << "\n";
    return 0;
}