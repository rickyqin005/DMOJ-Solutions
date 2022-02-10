#include <iostream>
using namespace std;
int main() {
    int direction[8][2] = {
    			{0,1},{1,0},{0,-1},{-1,0},
    			{1,1},{1,-1},{-1,-1},{-1,1}
    	};
    int N, M;
    cin >> N >> M;
    bool isReachable[N][N];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            isReachable[i][j] = false;
        }
    }
    for(int i = 0; i < M; i++) {
        int r, c;
        cin >> r >> c;
        r--, c--;
        for(int j = 0; j < 8; j++) {
            int tempr = r, tempc = c;
            while(true) {
                if(tempr < 0 || tempr >= N || tempc < 0 || tempc >= N) break;
                isReachable[tempr][tempc] = true;
                tempr += direction[j][0], tempc += direction[j][1];
            }
        }
    }
    int ans = N*N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(isReachable[i][j]) ans--;
        }
    }
    cout << ans << "\n";
    return 0;
}