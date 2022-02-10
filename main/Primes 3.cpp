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
unordered_set<int> uset;
#define MAXN 100000
int arr[MAXN+1];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N; cin >> N;
    for(int i = 1; i <= MAXN; i++) arr[i] = i;
    random_shuffle(arr+1, arr+N+1);
    for(int i = 1; i <= MAXN; i++) uset.insert(arr[i]);

    int sqr = sqrt(MAXN);
    uset.erase(1);
    for(int i = 2; i <= sqr; i++) {
        for(int j = i*i; j <= MAXN; j += i) uset.erase(j);
    }
    int cnt = 0;
    for(int i = 2; i <= MAXN; i++) {
        if(uset.find(i) != uset.end()) {
            cout << i << "\n";
            cnt++;
        }
        if(cnt == N) break;
    }
    return 0;
}