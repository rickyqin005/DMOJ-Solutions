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
int square(int x) {return x*x;}
pii arr[2001];
int vis[2001];
int dis[2001][2001];
int ans[2001];
struct Comp{public: bool operator()(pii a, pii b) {return dis[a.f][a.s] > dis[b.f][b.s];}};
vector<pii> vect1;
vector<vector<pii>> vect2;// group by length
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    memset(ans, 0, sizeof(ans));
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i].f >> arr[i].s;
    for(int i = 0; i <= N; i++) {
        for(int j = i+1; j <= N; j++) {
            dis[i][j] = dis[j][i] = (square(arr[i].f-arr[j].f) + square(arr[i].s-arr[j].s));
            vect1.pb(mp(i,j));
        }
    }
    sort(vect1.begin(), vect1.end(), Comp());
    vect2.pb({vect1[0]});
    for(int i = 1; i < vect1.size(); i++) {
        if(dis[vect1[i].f][vect1[i].s] == dis[vect1[i-1].f][vect1[i-1].s]) vect2.back().pb(vect1[i]);
        else vect2.pb({vect1[i]});
    }
    vis[0] = true;
    for(vector<pii> currLen: vect2) {
        vector<pii> currAns;
        for(pii edge: currLen) {
            if(vis[edge.f] && edge.s != 0) {
                vis[edge.s] = true;
                currAns.pb(mp(edge.s, ans[edge.f]+1));
            }
            if(vis[edge.s] && edge.f != 0) {
                vis[edge.f] = true;
                currAns.pb(mp(edge.f, ans[edge.s]+1));
            }
        }
        for(pii p: currAns) {
            ans[p.f] = max(ans[p.f], p.s);
        }
    }
    int finalAns = 0;
    for(int i = 1; i <= N; i++) finalAns = max(finalAns, ans[i]);
    cout << finalAns << "\n";
    return 0;
}