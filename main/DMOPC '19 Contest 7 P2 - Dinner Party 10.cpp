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
int N;
int arr[1000000];
int ans[1000000];
void check(int num0) {
    ans[0] = num0;
    for(int i = 1; i < N; i++) ans[i] = arr[i]-ans[(i-1+N)%N];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    check(0);
    //for(int i = 0; i < N; i++) {cout << ans[i] << " ";} cout << "\n";

    if(N%2 == 1) {
        if((arr[0]-ans[N-1])%2 == 1) {cout << "NO" << "\n"; exit(0);}
        int diff = (arr[0]-ans[N-1])/2;
        for(int i = 0; i < N; i++) ans[i] += diff * (i%2==0 ? 1 : -1);
        for(int i = 0; i < N; i++) {
            if(ans[i] < 0) {cout << "NO" << "\n"; exit(0);}
        }
    } else {
        if(arr[0] != ans[N-1]) {cout << "NO" << "\n"; exit(0);}
        int oddmin = INT_MAX, evenmin = INT_MAX;
        for(int i = 0; i < N; i++) {
            if(i%2 == 0) oddmin = min(oddmin, ans[i]);
            else evenmin = min(evenmin, ans[i]);
        }
        if(evenmin < 0) {cout << "NO" << "\n"; exit(0);}
        if(oddmin < 0) {
            if(abs(oddmin) > evenmin) {cout << "NO" << "\n"; exit(0);}
            int diff = abs(oddmin);
            for(int i = 0; i < N; i++) ans[i] += diff * (i%2==0 ? 1 : -1);
        }
    }
    //for(int i = 0; i < N; i++) {cout << ans[i] << " ";} cout << "\n";
    int M = accumulate(ans, ans+N, 0);
    cout << "YES" << "\n";
    cout << M << "\n";
    for(int i = 0; i < N; i++) {
        for(int j = 1; j <= ans[i]; j++) cout << i << " " << (i+1)%N << "\n";
    }
    return 0;
}