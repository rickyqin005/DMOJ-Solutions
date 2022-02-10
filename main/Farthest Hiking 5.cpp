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
string str;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int M,N,U,F,D; cin >> M >> N >> U >> F >> D;
    cin >> str;
    int tt = 0;
    int cnt = 0;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == 'u') tt += U+D;
        else if(str[i] == 'f') tt += 2*F;
        else if(str[i] == 'd') tt += D+U;
        if(tt > M) break;
        cnt++;
    }
    cout << cnt << "\n";
}