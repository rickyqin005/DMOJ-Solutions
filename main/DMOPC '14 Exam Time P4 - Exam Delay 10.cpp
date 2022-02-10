#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807
#define MAX_DOUBLE 1e18
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, double> pid;
typedef pair<double, int> pdi;
typedef pair<pii, int> piipi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef unordered_set<int> u_si;
typedef unordered_map<string, int> u_msi;

#define MAXN 1000
int V, E;
vector<pdi> adj[MAXN+1];
double dis[MAXN+1];
int numE[MAXN+1];
bool inQ[MAXN+1];
class Comp {
public:
    bool operator()(int a, int b) {
        return dis[a] > dis[b];
    }
};
priority_queue<int, vi, Comp> pq;
double dijkstra(int A, int B) {
    fill_n(dis, MAXN+1, MAX_DOUBLE);
    fill_n(numE, MAXN+1, MAX_INT);
    fill_n(inQ, MAXN+1, false);
    dis[A] = 0;
    numE[A] = 0;
    pq.push(A);
    double val;
    while(!pq.empty()) {
        int curr = pq.top();
        pq.pop();
        inQ[curr] = false;
        for(pdi edge: adj[curr]) {
            val = dis[curr] + edge.f;
            if(val < dis[edge.s]) {
                dis[edge.s] = val;
                numE[edge.s] = numE[curr]+1;
                if(!inQ[edge.s]) {
                    pq.push(edge.s);
                    inQ[edge.s] = true;
                }
            } else if(val == dis[edge.s]) {
                numE[edge.s] = min(numE[edge.s], numE[curr]+1);
            }
        }
    }
    return dis[B];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> V >> E;
    for(int i = 0,m,n,d,s; i < E; i++) {
        cin >> m >> n >> d >> s;
        adj[m].pb(mp((double)d/s*60,n));
        adj[n].pb(mp((double)d/s*60,m));
    }
    double ans = dijkstra(1, V);
    cout << numE[V] << "\n";
    cout << round(ans/0.75-ans) << "\n";
    return 0;
}