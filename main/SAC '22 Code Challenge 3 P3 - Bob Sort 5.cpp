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
ll arr[100001];
ll POS = 1;
bool comp(ll a, ll b) {return (a%POS - a%(POS/10)) < (b%POS - b%(POS/10));}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    ll maxa = 0;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        maxa = max(maxa, arr[i]);
    }
    while(true) {
        POS *= 10;
        stable_sort(arr+1, arr+N+1, comp);
        cout << arr[1];
        for(int i = 2; i <= N; i++) {cout << " " << arr[i];} cout << "\n";
        if(POS > maxa) break;
    }
    return 0;
}