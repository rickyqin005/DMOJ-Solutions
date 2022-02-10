#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
#define MAXN 1000000
pii stk[MAXN+1];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(stk, 0, sizeof(stk));
    int N; cin >> N;
    int top = 0;
    stk[top] = mp(INT_MAX, 1);
    for(int i = 1,curr; i <= N; i++) {
        cin >> curr;
        while(stk[top].f <= curr) {
            stk[top] = mp(0,0);
            top--;
        }
        top++;
        stk[top] = mp(curr,i);
        //for(int j = 0; j <= 5; j++) cout << stk[j].f << " ";
        //cout << "\n";
        cout << stk[top].s-stk[top-1].s << " ";
    }
    cout << "\n";
    return 0;
}