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
int arr[102];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i = 1,N,M,D,ans,n,pos; i <= 10; i++) {
        memset(arr, 0x7f, sizeof(arr));
        cin >> N >> M >> D; ans = 0; n = N; pos = 1;
        for(int j = 1; j <= M; j++) {cin >> arr[j];}
        sort(arr+1, arr+M+1);
        for(int j = 1; j <= D; j++) {
            if(n == 0) {
                n = N; ans++;
            }
            while(arr[pos] <= j) {
                N++; n++;
                pos++;
            }
            n--;
        }
        cout << ans << "\n";
    }
    return 0;
}