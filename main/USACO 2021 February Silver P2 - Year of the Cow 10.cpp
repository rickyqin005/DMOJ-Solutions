#include<bits/stdc++.h>
#include<iostream>
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

set<int, greater<int>> group;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int N, K; cin >> N >> K;
    for(int i = 0,n; i < N; i++) {
        cin >> n;
        n /= 12;
        group.insert(n);
    }
    K--;
    int len = group.size();
    int gap[len] = {0};
    auto it = group.begin();
    int prev = *it; it++;
    for(int i = 0; it != group.end(); it++, i++) {
        gap[i] = prev-*it;
        prev = *it;
    }
    gap[len-1] = prev+1;
    sort(gap, gap+len, greater<int>());
    int ans = *group.begin()+1;
    for(int i = 0; i < len && i < K; i++) {
        ans -= gap[i]-1;
    }
    cout << ans*12 << "\n";
    return 0;
}