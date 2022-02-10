#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int MOD = 1000000007;
    int N; cin >> N;
    long P, Q; cin >> P >> Q;
	int lastInc[N+1] = {0};
	long KP = N*P;
	int day; cin >> day;
	cout << day << " ";
	lastInc[N-KP/Q] = day;
	KP -= P;
	for(int i = 1; i < N; i++, KP -= P) {
        int curr; cin >> curr;
        day = ((lastInc[i]*2)%MOD+curr)%MOD;
		cout << day << " ";
        lastInc[N-KP/Q] = day;
    }
	cout << endl;
    return 0;
}