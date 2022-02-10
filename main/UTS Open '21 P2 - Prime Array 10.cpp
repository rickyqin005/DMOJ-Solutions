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
int arr[101];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int K; cin >> K;
    if(K == 0) {cout << 1 << "\n" << 2 << "\n"; exit(0);}
    int arrLen = 0;
    int sumSeries = 0;
    while(true) {
        arrLen++;
        sumSeries += arrLen;
        if(sumSeries >= K) break;
    }
    
    int diff = sumSeries-K;
    int num3 = diff/3;
    int num1 = diff%3;
    //cout << arrLen << " " << sumSeries << " " << num3 << " " << num1 << "\n";
    cout << arrLen << "\n";
    int idx = 0;
    for(int i = 1; i <= num3; i++) {
        arr[idx+1] = 2;
        arr[idx+2] = 2;
        arr[idx+3] = 1;
        idx += 3;
        //cout << 2 << " " << 2 << " " << 1 << " ";
    }
    for(int i = 1; i <= num1; i++) {
        if(i == num1) {
            arr[idx+1] = 2;
            idx++;
            //cout << 2 << " ";
        } else {
            arr[idx+1] = 2;
            arr[idx+2] = 1;
            idx += 2;
            //cout << 2 << " " << 1 << " ";
        }
    }
    for(int i = idx+1; i <= arrLen; i++) {
        arr[i] = 1;
        //cout << 1 << " ";
    }
    for(int i = 1; i <= arrLen; i++) {
        if(i != arrLen) cout << arr[i] << " ";
        else cout << arr[i];
    }
    cout << "\n";
    return 0;
}