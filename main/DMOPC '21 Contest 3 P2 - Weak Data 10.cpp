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
ll arr[1000002];
void printAns(int N, int mid) {
    cout << N << "\n";
    for(int i = 1; i <= N; i++) {
        if(i == mid) cout << 1;
        else cout << 2;
        if(i != N) cout << " ";
    }
    cout << "\n";
    return;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll K; cin >> K;
    if(K > 500000500000) {cout << -1 << "\n"; return 0;}
    if(K == 0) {cout << 1 << "\n" << 1 << "\n"; return 0;}
    arr[0] = 0;
    int high = 0;
    for(int i = 1;; i++) {
        arr[i] = arr[i-1]+i;
        if(arr[i] > K) {
            high = i-1;
            break;
        }
    }
    if(arr[high] == K) {printAns(high,-1); return 0;}
    //for(int i = 0; i <= high; i++) {cout << arr[i] << " ";} cout << "\n";
    for(int i = 1; i <= high; i++) {
        auto it = lower_bound(arr, arr+high+1, K-arr[i]);
        if(*it == K-arr[i] && ((it-arr)+i+1) <= 1000000) {
            printAns((it-arr)+i+1, it-arr+1);
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}