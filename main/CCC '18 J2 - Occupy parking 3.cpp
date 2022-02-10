#include <bits/stdc++.h>

using namespace std;

int N, ans; string a, b;
int main() {
    cin >> N >> a >> b;
    for (int i = 0; i < N; i++) {
        if (a[i] == 'C' && b[i] == 'C') ans++;
    }
    cout << ans << endl;

    return 0;
}