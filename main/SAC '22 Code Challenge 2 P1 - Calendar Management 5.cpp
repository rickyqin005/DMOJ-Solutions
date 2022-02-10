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
pair<int, string> arr[101];
bool vis[101];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(vis, 0, sizeof(vis));
    int A,K; cin >> A >> K;
    for(int i = 1; i <= A; i++) {
        cin >> arr[i].f >> arr[i].s;
    }
    for(int i = 1,D; i <= K; i++) {
        cin >> D;
        for(int j = 1; j <= A; j++) {
            if(arr[j].f <= D) {
                if(!vis[j]) {
                    cout << arr[j].s << "\n";
                    vis[j] = true;
                }
            }
        }
    }
    return 0;
}