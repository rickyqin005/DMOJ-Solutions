#include <bits/stdc++.h>
using namespace std;
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
#define pb push_back
typedef long long int ll;
#define MAXN 5000000
vector<int> prime;
bool p1[31623];
bool p2[MAXN+1];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(p1, 0, sizeof(p1));
    memset(p2, 0, sizeof(p2));
    int N,M; cin >> N >> M;
    int sqr1 = (int)sqrt(M);
    int sqr2 = (int)sqrt(sqr1);

    for(int i = 4; i <= sqr1; i += 2) p1[i] = 1;
    for(int i = 3; i <= sqr2; i += 2) {
        if(p1[i]) continue;
        for(int j = i*i; j <= sqr1; j += i) p1[j] = 1;
    }
    prime.pb(2);
    for(int i = 3; i <= sqr1; i += 2) {
        if(!p1[i]) prime.pb(i);
    }
    for(int i: prime) {
        for(int j = max(i*i,(N+i-1)/i*i); j <= M; j += i) p2[j-N] = 1;
    }
    if(N == 1) p2[0] = 1;

    for(int i = 0; i < M-N+1; i++) {
        if(!p2[i]) cout << i+N << "\n";
    }
    return 0;
}