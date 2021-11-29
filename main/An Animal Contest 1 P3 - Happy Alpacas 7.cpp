#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef pair<int, pii> pipii;
int arr[1000001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(arr, 0, sizeof(arr));
    int N, X; cin >> N >> X;
    if((N-X)%2 == 0) {
        for(int i = 1; i <= X+1; i++) {arr[i] = 2;}
        for(int i = X+2; i <= N; i++) arr[i] = ((arr[i-1]==2)?1:2);
    } else {
        cout << -1 << "\n";
        return 0;
    }
    for(int i = 1; i <= N; i++) {
        cout << arr[i];
        if(i != N) cout << " ";
    } cout << endl;
    return 0;
}