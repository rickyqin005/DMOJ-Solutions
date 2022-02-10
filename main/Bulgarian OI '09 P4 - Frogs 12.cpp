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
int height[1000001];
int jump[1000001];
int ans[1000001];
vector<int> stk;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> height[i];
    for(int i = 1; i <= N; i++) cin >> jump[i];
    for(int i = N; i >= 1; i--) {
        while(!stk.empty() && height[i] >= stk.back()) {
            stk.pop_back();
        }
        stk.push_back(height[i]);
        if(jump[i] >= stk.size()) ans[i] = -1;
        else ans[i] = stk[stk.size()-1-jump[i]];
    }
    for(int i = 1; i <= N; i++) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}