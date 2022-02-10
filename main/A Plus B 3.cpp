#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N; cin >> N;
    for(int i = 1,a,b; i <= N; i++) {
        cin >> a >> b;
        cout << a+b << "\n";
    }
    return 0;
}