#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
typedef pair<int, pii> pipii;
unordered_set<string> str;
int arr[6];
string tostr[6];
string temp[12];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5];
        for(int j = 0; j < 6; j++) {
            tostr[j] = to_string(arr[j]);
            for(int k = tostr[j].length(); k <= 7; k++) tostr[j] += "-";
        }
        for(int j = 0; j < 6; j++) {
            temp[j*2] = ""; temp[j*2+1] = "";
            for(int k = 0; k < 6; k++) {
                temp[j*2] += tostr[(j+k)%6];
                temp[j*2+1] += tostr[(j-k+6)%6];
            }
            if(str.find(temp[j*2]) != str.end() || str.find(temp[j*2+1]) != str.end()) {
                cout << "Twin snowflakes found.\n"; return 0;
            }
        }
        str.insert(temp[0]);
    }
    cout << "No two snowflakes are alike.\n";
    return 0;
}