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
int arr[2001];
int grid[2001][2001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(grid, 0, sizeof(grid));
    int N,M,S,F,L,R; cin >> N >> M >> S >> F >> L >> R;
    for(int i = 1; i <= M; i++) cin >> arr[i];
    int lastF = -1;
    for(int i = M; i >= 1; i--) {
        if(arr[i] == F) {lastF = i; break;}
    }

    if(lastF == -1) {
        if(S != F) {cout << -1 << "\n"; exit(0);}
        if(L > (N-1)*M) {cout << -1 << "\n"; exit(0);}

        int cnt = 0;
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                if(i == S) continue;
                if(cnt < L) {
                    grid[i][j] = 1; cnt++;
                }
            }
        }

        cout << L << "\n";
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                cout << grid[i][j];
                if(j != M) cout << " ";
            } cout << "\n";
        }
    } else {
        int cnt = 0;
        if(S != F) {
            if(L > N*M-(M-lastF)) {cout << -1 << "\n"; exit(0);}
            if(R < 1) {cout << -1 << "\n"; exit(0);}
            L = max(L,1);
            
            grid[S][lastF] = 1; cnt++;//most important cell
            for(int i = 1; i <= N; i++) {
                if(i == S) continue;
                if(cnt < L) {
                    grid[i][lastF] = 1; cnt++;
                }
            }
            for(int i = 1; i <= N; i++) {
                if(i == F) continue;
                for(int j = 1; j <= M; j++) {
                    if(j == lastF) continue;
                    if(cnt < L) {
                        grid[i][j] = 1; cnt++;
                    }
                }
            }
            for(int j = 1; j < lastF; j++) {
                if(cnt < L) {
                    grid[F][j] = 1; cnt++;
                }
            }
        } else {
            if(L > N*M-(M-lastF)) {cout << -1 << "\n"; exit(0);}
            int cnt = 0;
            for(int i = 1; i <= N; i++) {
                if(cnt < L) {
                    grid[i][lastF] = 1; cnt++;
                }
            }
            for(int i = 1; i <= N; i++) {
                if(i == F) continue;
                for(int j = 1; j <= M; j++) {
                    if(j == lastF) continue;
                    if(cnt < L) {
                        grid[i][j] = 1; cnt++;
                    }
                }
            }
            for(int j = 1; j < lastF; j++) {
                if(cnt < L) {
                    grid[F][j] = 1; cnt++;
                }
            }
        }
        cout << L << "\n";
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                cout << grid[i][j];
                if(j != M) cout << " ";
            } cout << "\n";
        }
    }
    return 0;
}