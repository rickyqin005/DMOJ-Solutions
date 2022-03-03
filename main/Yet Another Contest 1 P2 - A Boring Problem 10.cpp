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
typedef pair<ll, ll> pll;
int N;
string str;
int col[200001];
int numb[200001];
int numw[200001];
vector<int> adj[200001];
ll ans = 0;
void dfs(int curr, int par) {
    ll cnt1 = 0;// -> B -> B
    ll cnt2 = 0;// -> B -> W
    ll cnt3 = 0;// -> W -> B
    ll cnt4 = 0;// -> W -> W
    for(int j: adj[curr]) {
        if(j != par) {
            if(col[curr]) {
                if(col[j]) {//BB
                    cnt1 += numb[j]-1;
                    cnt2 += numw[j];
                } else {//BW
                    cnt3 += numb[j]-1;
                    cnt4 += numw[j];
                }
            } else {
                if(col[j]) {//WB
                    cnt1 += numb[j];
                    cnt2 += numw[j]-1;
                } else {//WW
                    cnt3 += numb[j];
                    cnt4 += numw[j]-1;
                }
            }
        }
        if(j != par) dfs(j, curr);
    }
    for(int j: adj[curr]) {
        if(col[curr]) {
            if(col[j]) {//BB
                ans -= cnt4;
            } else {//BW
                ans -= cnt2 + cnt3 - (j != par ? numb[j]-1:0);
            }
        } else {
            if(col[j]) {//WB
                ans -= cnt2 + cnt3 - (j != par ? numw[j]-1:0);
            } else {//WW
                ans -= cnt1;
            }
        }
    }
    //cout << curr << " " << cnt1 << " " << cnt2 << " " << cnt3 << " " << cnt4 << " " << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(numb, 0, sizeof(numb));
    memset(numw, 0, sizeof(numw));
    cin >> N;
    cin >> str;
    for(int i = 1; i <= N; i++) col[i] = (str[i-1]=='B');
    for(int i = 1,u,v; i < N; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ans = (ll)N*(N-1)/2;
    //cout << ans << "\n";
    ans -= N-1;// num 2
    //cout << ans << "\n";
    for(int i = 1; i <= N; i++) {
        int cnt1 = 0;// same
        int cnt2 = 0;// diff
        for(int next: adj[i]) {
            if(col[next] == col[i]) ans -= cnt2;
            else ans -= cnt1 + cnt2;
            if(col[next] == col[i]) cnt1++;
            else cnt2++;
        }
        //cout << cnt1 << " " << cnt2 << " " << ans << "\n";
    }
    //cout << ans << "\n";
    for(int i = 1; i <= N; i++) {
        for(int next: adj[i]) {
            if(col[next]) numb[i]++;
            else numw[i]++;
        }
    }
    dfs(1,-1);
    cout << ans << "\n";
    return 0;
}