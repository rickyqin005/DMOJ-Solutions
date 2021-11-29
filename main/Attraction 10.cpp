#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807
#define MAX_DOUBLE 1e18
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef vector<int> vii;
typedef vector<ll> vll;
int arr[200001];
vector<int> vect;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for(int i = 0,N,A,B,ans,pos,gap,gap3; i < T; i++) {
        cin >> N >> A >> B;
        vect.clear();
        for(int j = 0; j < A; j++) {cin >> arr[j];}
        sort(arr, arr+A);
        vect.pb(arr[0]-1);
        vect.pb(N-arr[A-1]);
        gap3 = 0;
        for(int j = 1; j < A; j++) {
            gap = arr[j]-arr[j-1]-1;
            if(gap%2 == 0) {
                vect.pb(gap/2);
                vect.pb(gap/2);
            } else {
                if(gap == 1) vect.pb(1);
                else if(gap == 3) {
                    vect.pb(2);
                    gap3++;
                } else {
                    vect.pb(gap/2+1);
                    vect.pb(gap/2-1);
                    vect.pb(1);
                }
            }
        }
        sort(vect.begin(), vect.end(), greater<int>());
        ans = 0;
        for(pos = 0; pos < B && pos < vect.size(); pos++) {
            if(vect[pos] == 0) break;
            ans += vect[pos];
        }
        for(int j = 0; j < gap3 && pos < B-1; j++, pos += 2) {
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}