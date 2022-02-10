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
int arr[5001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(arr, 0, sizeof(arr));
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {arr[i] = i;}
    int response;
    while(true) {
        random_shuffle(arr+1, arr+N+1);
        for(int j = 1; j <= N; j++) {
            cout << arr[j] << " ";
        } cout << endl;
        cin >> response;
        if(response == 0 || response == -1) break;
    }
    return 0;
}