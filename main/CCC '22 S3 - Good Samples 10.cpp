#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
ll ans[1000001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(ans, 0, sizeof(ans));
    ll N,M; ll K; cin >> N >> M >> K;
    ll add = K-N;
    if(add < 0) {cout << -1 << "\n"; exit(0);}
    fill(ans+1, ans+N+1, 1);
    if(M == 1) {
        if(K != N) {cout << -1 << "\n"; exit(0);}
        for(int i = 1; i <= N; i++) {cout << ans[i] << " ";} cout << "\n";
        return 0;
    }
    ll triidx = 0;
    int idx;
    for(idx = 2; idx <= M && idx <= N; idx++) {
        if(triidx+1 > add) break;
        triidx++;
        add -= triidx;
        ans[idx] = idx;
    }

    //cout << idx << " " << triidx << " " << add << "\n";
    
    for(; idx <= N; idx++) {
        if(add == 0) break;
        if(add < M) {
            ans[idx] = ans[idx-add-1];
            add = 0;
        } else {
            ans[idx] = ans[idx-M];
            add -= M-1;
        }
    }
    if(add > 0) {cout << -1 << "\n"; exit(0);}
    for(; idx <= N; idx++) ans[idx] = ans[idx-1];

    for(int i = 1; i <= N; i++) {cout << ans[i] << " ";} cout << "\n";
    return 0;
}