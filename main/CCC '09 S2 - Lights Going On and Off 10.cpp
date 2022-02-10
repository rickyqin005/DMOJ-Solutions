#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef pair<int, pii> pipii;
int lit[31];
unordered_set<int> num;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int R,C; cin >> R >> C;
    for(int i = 1,b; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            cin >> b;
            lit[i] <<= 1;
            lit[i] += b;
        }
    }
    int curr = 0;
    for(int i = R,curr; i >= 1; i--) {
        curr ^= lit[i];
        num.insert(curr);
    }
    cout << num.size() << endl;
}