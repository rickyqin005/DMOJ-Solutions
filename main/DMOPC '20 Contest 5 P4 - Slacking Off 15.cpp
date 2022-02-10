#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 2223243435546756677
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
vector<string> in;
vector<vector<char>> grid;
unordered_map<ll, int> umap;
ll hashll[200001];
string str;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N,M; cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        cin >> str; in.pb(str);
    }
    if(N > M) {
        grid = vector<vector<char>>(M+1, vector<char>(N+1));
        for(int i = 1; i <= M; i++) {
            for(int j = 1; j <= N; j++) grid[i][j] = in[j-1][M-i];
        }
        swap(N, M);
    } else {
        grid = vector<vector<char>>(N+1, vector<char>(M+1));
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) grid[i][j] = in[i-1][j-1];
        }
    }
    /*for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) cout << grid[i][j];
        cout << "\n";
    }*/
    ll ans = 0;
    for(int i = 1; i < N; i++) {
        memset(hashll, 0, sizeof(hashll));
        for(int k = 1; k <= M; k++) hashll[k] = (grid[i][k]=='Y');
        for(int j = i+1; j <= N; j++) {
            for(int k = 1; k <= M; k++) {
                if(grid[i][k] != grid[j][k]) {
                    for(pair<ll, int> col: umap) ans += (ll)col.s*(col.s-1)/2;
                    umap.clear();
                }
                hashll[k] = (hashll[k]*2+(grid[j][k]=='Y'))%MOD;
                umap[hashll[k]]++;
            }
            for(pair<ll, int> col: umap) ans += (ll)col.s*(col.s-1)/2;
            umap.clear();
        }
    }
    cout << ans << "\n";
    return 0;
}