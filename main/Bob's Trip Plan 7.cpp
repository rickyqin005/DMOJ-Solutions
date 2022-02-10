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
int arr[100002];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N; cin >> N;
    arr[0] = 0;
    arr[N+1] = 0;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    int dist = 0;
    for(int i = 1; i <= N+1; i++) dist += abs(arr[i]-arr[i-1]);
    for(int i = 1; i <= N; i++) {
        cout << dist-abs(arr[i]-arr[i-1])-abs(arr[i+1]-arr[i])+abs(arr[i+1]-arr[i-1]) << "\n";
    }
}