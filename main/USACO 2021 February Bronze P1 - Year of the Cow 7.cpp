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
unordered_map<string, int> year;
unordered_map<string, pii> name;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    year["Ox"] = 0;
    year["Tiger"] = 1;
    year["Rabbit"] = 2;
    year["Dragon"] = 3;
    year["Snake"] = 4;
    year["Horse"] = 5;
    year["Goat"] = 6;
    year["Monkey"] = 7;
    year["Rooster"] = 8;
    year["Dog"] = 9;
    year["Pig"] = 10;
    year["Rat"] = 11;
    name["Bessie"] = mp(year["Ox"], 0);
    int N; cin >> N;
    string str1, str2, str3; bool ord; int diff;
    for(int i = 0; i < N; i++) {
        cin >> str1;
        cin >> str2 >> str2 >> str2;
        if(str2 == "previous") ord = false;
        else ord = true;
        cin >> str2; cin >> str3 >> str3 >> str3;
        if(!ord) {
            diff = (name[str3].f+12-year[str2]+11)%12+1;
        } else {
            diff = -((year[str2]+12-name[str3].f+11)%12+1);
        }
        name[str1] = mp(year[str2], name[str3].s+diff);
    }
    cout << abs(name["Elsie"].s) << "\n";
    return 0;
}