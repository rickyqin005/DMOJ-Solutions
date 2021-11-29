#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define f first
#define s second
typedef pair<int, int> pii;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string a, b; cin >> a >> b;
    ll A = 0, B = 0, val = 1;
    for(int i = 0; i < a.length(); i++) {
        A += (a[i]-48)*val;
        val *= 10;
    }
    val = 1;
    for(int i = 0; i < b.length(); i++) {
        B += (b[i]-48)*val;
        val *= 10;
    }
    cout << min(A,B) << "\n";
    return 0;
}