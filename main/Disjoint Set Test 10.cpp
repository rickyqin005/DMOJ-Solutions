#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define MAXN 100000
int par[MAXN+1];
int wei[MAXN+1];
int get(int a) {
    if(par[a] != a) par[a] = get(par[a]);
    return par[a];
}
bool join(int a, int b) {
    a = get(a); b = get(b);
    if(a != b) {
        if(wei[a] > wei[b]) {
            par[b] = a;
            wei[a] += wei[b]+1;
        } else {
            par[a] = b;
            wei[b] += wei[a]+1;
        }
        return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset(wei, 0, sizeof(wei));
    int N, M; cin >> N >> M;
    for(int i = 1; i <= N; i++) par[i] = i;
    if(M+1 < N) {
        cout << "Disconnected Graph" << "\n";
        return 0;
    }
    int mst[N-1];
    int edge = 0;
		for(int i = 1,u,v; i <= M && edge < N; i++) {
            cin >> u >> v;
			if(join(u,v)) {
				mst[edge] = i;
				edge++;
			}
		}
		if(edge != N-1) cout << "Disconnected Graph" << "\n";
		else {
			for(int j: mst) cout << j << "\n";
		}
    return 0;
}