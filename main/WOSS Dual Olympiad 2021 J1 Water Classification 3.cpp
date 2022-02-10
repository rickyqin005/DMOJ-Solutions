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
    int T; cin >> T;
    if(T <= 0) cout << "S" << "\n";
    else if(T >= 100) cout << "G" << "\n";
    else cout << "L" << "\n";
}