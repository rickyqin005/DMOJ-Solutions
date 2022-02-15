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
    ios_base::sync_with_stdio(0); cin.tie(0);
    int H; cin >> H;
    int S; cin >> S;
    int Q; cin >> Q;
    for(int i = 1; i <= Q; i++) cout << H-S*i << "\n";
    return 0;
}