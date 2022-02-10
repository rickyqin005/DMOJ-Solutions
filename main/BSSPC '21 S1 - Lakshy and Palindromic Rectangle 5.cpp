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
char arr[2001][2001];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N,M; cin >> N >> M;
    string str;
    for(int i = 1; i <= N; i++) {
        cin >> str;
        for(int j = 1; j <= M; j++) {
            arr[i][j] = str[j-1];
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            unordered_set<char> letter;
            if(arr[i][j] != '.') letter.insert(arr[i][j]);
            if(arr[i][M-j+1] != '.') letter.insert(arr[i][M-j+1]);
            if(arr[N-i+1][j] != '.') letter.insert(arr[N-i+1][j]);
            if(arr[N-i+1][M-j+1] != '.') letter.insert(arr[N-i+1][M-j+1]);
            if(letter.size() > 1) {cout << -1 << "\n"; exit(0);}
            if(letter.size() == 0) letter.insert('a');
            arr[i][j] = arr[i][M-j+1] = arr[N-i+1][j] = arr[N-i+1][M-j+1] = *letter.begin();
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) cout << arr[i][j];
        cout << "\n";
    }
    return 0;
}