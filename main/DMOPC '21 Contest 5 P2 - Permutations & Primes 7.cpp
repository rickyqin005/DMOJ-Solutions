#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N; cin >> N;
    if(N == 1) {cout << 1 << "\n"; exit(0);}
    if(N == 2) {cout << -1 << "\n"; exit(0);}
    cout << "1 3 2";
    for(int i = 4; i <= N; i++) {cout << " " << i;}
    cout << "\n";
    return 0;
}