#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef pair<int, pii> pipii;
vector<int> room[100001];
vector<int> stud[100001];
int f[100001];
ll dis[100001];
class Comp {
public: bool operator()(int a, int b) {return dis[a] > dis[b];}
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dis, 0x7f, sizeof(dis));
    dis[1] = 0;
    int N,C,K; cin >> N >> C >> K;
    for(int i = 1; i <= N; i++) {cin >> f[i];}
    for(int i = 1,c,v; i <= N; i++) {
        cin >> c;
        for(int j = 1; j <= c; j++) {
            cin >> v; room[i].pb(v);
            stud[v].pb(i);
        }
    }
    priority_queue<int, vector<int>, Comp> pq;
    pq.push(1);
    while(!pq.empty()) {
        int curr = pq.top(); pq.pop();
        for(int i: room[curr]) {
            for(int j: stud[i]) {
                if(dis[curr]+abs(f[curr]-f[j])+K < dis[j]) {
                    dis[j] = dis[curr]+abs(f[curr]-f[j])+K;
                    pq.push(j);
                }
            }
        }
    }
    for(int i = 1; i <= N; i++) {cout << (dis[i]==9187201950435737471?-1:dis[i]) << "\n";}
    return 0;
}