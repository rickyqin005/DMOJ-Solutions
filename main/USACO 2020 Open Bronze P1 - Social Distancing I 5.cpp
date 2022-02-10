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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    string str; cin >> str;
    int first = -1, last = INT_MAX;
    for(int i = 0; i < N; i++) {
        if(str[i] == '1') {
            first = i; break;
        }
    }
    for(int i = N-1; i > first; i--) {
        if(str[i] == '1') {
            last = i; break;
        }
    }
    if(first == -1 && last == INT_MAX) {
        //no cows
        cout << N-1 << "\n"; return 0;
    } else if(last == INT_MAX) {
        //one cow
        cout << max(max(first, N-first-1)/2, min(first, N-first-1)) << "\n"; return 0;
    }
    int max1 = 0, max2 = 0, cnt = 0, prev = first, dist, minDist = INT_MAX;
    for(int i = first+1; i <= last; i++) {
        if(str[i] == '1') {
            dist = i-prev;
            prev = i;
            minDist = min(minDist, dist);
            if(dist == 1) continue;
            if(dist >= max1) {
                max2 = max1;
                max1 = dist;
            } else if(dist >= max2) {
                max2 = dist;
            }
            cnt++;
        }
    }
    int ans = max(max(first, N-last-1)/2, min(first, N-last-1));
    ans = max(ans, min(max(first, N-last-1), max1/2));
/*
    cout << first << " " << last << "\n";
    cout << max1 << " " << max2 << "\n";
    cout << cnt << "\n";
    cout << minDist << "\n";
    cout << "ans: " << ans << "\n";
*/
    ans = max(ans, max1/3);

    if(cnt >= 2) {
        ans = max(ans, min(max1/2, max2/2));
    }
    ans = min(ans, minDist);
    cout << ans << "\n";
    return 0;
}