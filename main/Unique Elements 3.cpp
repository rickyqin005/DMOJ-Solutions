#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_set<int> uset;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N; cin >> N;
    for(int i = 1,a; i <= N; i++) {
        cin >> a;
        uset.insert(a);
    }
    cout << uset.size() << "\n";
    return 0;
}