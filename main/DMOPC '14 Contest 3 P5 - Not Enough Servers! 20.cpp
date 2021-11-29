#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef pair<int, pii> pipii;
typedef pair<int, ll> pil;
int test[51];
ll dp[1<<20];
queue<pii> q;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(test, 0, sizeof(test));
    memset(dp, -1, sizeof(dp));
    int N,M; cin >> N >> M;
    string str; bool wa;
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        cin >> str; wa = 0;
        for(int j = 1; j <= M; j++) {
            if(str[j-1] == 'X') wa = 1;
            test[j] |= ((str[j-1] == 'X')<<(N-i));
        }
        ans |= (wa<<(N-i));
    }
    dp[0] = 0;
    q.push(mp(0,0));
    while(!q.empty()) {
        pii curr = q.front(); q.pop();
        for(int i = curr.s+1; i <= M; i++) {
            if(dp[curr.f|test[i]] == -1) {
                dp[curr.f|test[i]] = (dp[curr.f]|(1LL<<(M-i)));
                q.push(mp(curr.f|test[i],i));
            }
        }
    }
    if(bitset<64>(dp[ans]).count() == 0) cout << "1\n1\n";
    else {
        cout << bitset<64>(dp[ans]).count() << "\n";
        for(int i = 1; i <= M; i++) {
            if((dp[ans]>>(M-i))&1LL) cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}