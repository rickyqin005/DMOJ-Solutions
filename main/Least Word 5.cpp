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
string arr[1001];
string temp;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N,L; cin >> N >> L;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    for(int i = 1; i <= N; i++) {
        temp = arr[i];
        reverse(temp.begin(), temp.end());
        if(temp.compare(arr[i]) < 0) arr[i] = temp;
    }
    sort(arr+1, arr+N+1);
    for(int i = 1; i <= N; i++) {
        cout << arr[i];
    }
    cout << "\n";
}