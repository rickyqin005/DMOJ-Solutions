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
int arr[1000001];
struct qry {
    int l,r,id;
    qry(){}
};
bool comp1(qry a, qry b) {return a.l > b.l;}
bool comp2(int a, int b) {return a > b;}
qry query[1000001];
vector<int> stk1;
vector<int> stk2;
int ans[1000001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,Q; cin >> N >> Q;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    for(int i = 1; i <= Q; i++) {
        cin >> query[i].l >> query[i].r;
        query[i].id = i;
    }
    sort(query+1, query+Q+1, comp1);
    int pos = N;
    for(int i = 1; i <= Q; i++) {
        for(; pos >= query[i].l; pos--) {
            while(!stk1.empty() && arr[pos] >= stk1.back()) {
                stk1.pop_back();
                stk2.pop_back();
            }
            stk1.pb(arr[pos]);
            stk2.pb(pos);
        }
        ans[query[i].id] = stk2.size()-(lower_bound(stk2.begin(), stk2.end(), query[i].r, comp2)-stk2.begin());
    }
    for(int i = 1; i <= Q; i++) cout << ans[i] << "\n";
    return 0;
}