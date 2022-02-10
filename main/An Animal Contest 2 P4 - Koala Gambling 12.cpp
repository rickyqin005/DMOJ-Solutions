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
int arr[601];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T; cin >> T;
    for(int t = 1; t <= T; t++) {
        int N; cin >> N;
        for(int i = 1; i <= N; i++) cin >> arr[i];
        sort(arr+1, arr+N+1);
        if(N%2 == 1) {
            for(int i = 1; i <= N; i++) {
                cout << arr[i];
                if(i != N) cout << " ";
            } cout << "\n";
            continue;
        } else {
            if(arr[1] == arr[N]) {cout << -1 << "\n"; continue;}
            for(int i = 1; i <= N/2; i++) {
                if(i != 1) cout << " ";
                cout << arr[i] << " " << arr[N+1-i];
            } cout << "\n";
        }

    }
    return 0;
}