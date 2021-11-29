#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef pair<int, pii> pipii;
bool arr[100001];
bool arr2[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(arr, 0, sizeof(arr));
    memset(arr2, 0, sizeof(arr2));
    int N; ll T; cin >> N >> T;
    string str; cin >> str;
    for(int i = 1; i <= N; i++) arr[i] = (str[i-1]=='1');
    ll pow = 1;
    while(pow <= T) {
        if(T&pow) {
            for(int i = 1; i <= N; i++) {
                arr2[i] = arr[(i-pow%N+N-1)%N+1]^arr[(i+pow%N-1)%N+1];
            }
            for(int i = 1; i <= N; i++) arr[i] = arr2[i];
        }
        pow *= 2;
    }
    for(int i = 1; i <= N; i++) cout << arr[i];
    cout << "\n";
    return 0;
}