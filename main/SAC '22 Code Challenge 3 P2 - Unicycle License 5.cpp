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
    double M; cin >> M;
    printf("%.06f\n", sqrt(1.0/12*(M-23.0/48))+5.0/24);
    return 0;
}