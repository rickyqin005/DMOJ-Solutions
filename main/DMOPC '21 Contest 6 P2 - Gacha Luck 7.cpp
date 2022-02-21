#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> pii;
string str;
vector<pii> len0;
bool comp(pii a, pii b) {return a.s-a.f+1 > b.s-b.f+1;}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N,K; cin >> N >> K;
    cin >> str;
    int ans = 0;
    for(int i = 0; i < N;) {
        if(str[i] == '0') {
            int j = i+1;
            while(j < N && str[j] == '0') j++;
            len0.pb(mp(i+1,j));
            i = j;
        } else i++;
    }
    if(K >= len0.size()) {
        for(pii p: len0) ans += p.s-p.f+1;
        cout << ans << "\n"; exit(0);
    }
    sort(len0.begin(), len0.end(), comp);
    for(int i = 0; i < K; i++) {
        ans += len0[i].s-len0[i].f+1;
    }
    cout << ans << "\n";
    return 0;
}