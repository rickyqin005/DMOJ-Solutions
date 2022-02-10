#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;
vector<int> adj[200001];
int dis[200001];
queue<int> q;
multiset<int> ans;
int arr[200001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dis, -1, sizeof(dis));
    int N,W,D; cin >> N >> W >> D;
    for(int i = 1,a,b; i <= W; i++) {
        cin >> a >> b;
        adj[b].pb(a);
    }

    dis[N] = 0;
    q.push(N);
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        for(int i: adj[curr]) {
            if(dis[i] == -1) {
                dis[i] = dis[curr]+1;
                q.push(i);
            }
        }
    }
    for(int i = 1,s; i <= N; i++) {
        cin >> s;
        if(dis[s] != -1) ans.insert(i-1+dis[s]);
        arr[i] = s;
    }
    for(int i = 1,x,y; i <= D; i++) {
        cin >> x >> y;
        if(dis[arr[x]] != -1) ans.erase(ans.find(x-1+dis[arr[x]]));
        if(dis[arr[y]] != -1) ans.erase(ans.find(y-1+dis[arr[y]]));
        swap(arr[x], arr[y]);
        if(dis[arr[x]] != -1) ans.insert(x-1+dis[arr[x]]);
        if(dis[arr[y]] != -1) ans.insert(y-1+dis[arr[y]]);
        cout << *ans.begin() << "\n";
    }
    return 0;
}