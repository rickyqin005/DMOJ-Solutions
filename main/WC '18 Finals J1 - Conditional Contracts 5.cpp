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
typedef pair<int, double> pid;
typedef pair<double, int> pdi;
typedef pair<pii, int> piipi;
typedef vector<int> vii;
typedef vector<ll> vll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int N; cin >> N;
    unordered_map<int, int> freq;
    for(int i = 0,n; i < N; i++) {
        cin >> n;
        freq[n]++;
    }
    int max1 = 0, max2 = 0;
    for(pii i: freq) {
        if(i.s >= max1) {
            max2 = max1;
            max1 = i.s;
        } else if(i.s >= max2) {
            max2 = i.s;
        }
    }
    cout << max1+max2 << "\n";
    return 0;
}