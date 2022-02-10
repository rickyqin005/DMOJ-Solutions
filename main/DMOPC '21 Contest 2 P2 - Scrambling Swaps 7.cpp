#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;
int a[301];
int idx[301];
int perm[301];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N,Q; cin >> N >> Q; char c;
    for(int i = 1; i <= N; i++) {
        a[i] = i;
        idx[i] = i;
    }
    for(int i = 1,x,y; i <= Q; i++) {
        cin >> c;
        if(c == 'B') {
            cin >> x >> y;
            swap(idx[x],idx[y]);
            swap(a[idx[x]],a[idx[y]]);
        } else if(c == 'E') {
            cin >> x >> y;
            swap(a[x],a[y]);
            swap(idx[a[x]],idx[a[y]]);
        } else {
            for(int j = 1,p; j <= N; j++) {
                cin >> p;
                perm[a[j]] = p;
            }
            for(int j = 1; j <= N; j++) {
                cout << perm[j];
                if(j != N) cout << " ";
            }
            cout << "\n";
        }
        /*for(int j = 1; j <= N; j++) cout << a[j] << " ";
        cout << "\n";
        for(int j = 1; j <= N; j++) cout << idx[j] << " ";
        cout << "\n\n";*/
    }
    return 0;
}