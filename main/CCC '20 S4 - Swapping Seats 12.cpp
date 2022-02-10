#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;
string str;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> str;
    int N = str.length();
    int A = 0, B = 0, C = 0;
    int AB = 0, AC = 0, BA = 0, BC = 0, CA = 0, CB = 0;
    for(int i = 0; i < N; i++) {
        if(str[i] == 'A') A++;
        else if(str[i] == 'B') B++;
        else C++;
    }
    for(int i = 0; i < A; i++) {
        if(str[i] == 'B') BA++;
        else if(str[i] == 'C') CA++;
    }
    for(int i = A; i < A+B; i++) {
        if(str[i] == 'A') AB++;
        else if(str[i] == 'C') CB++;
    }
    for(int i = A+B; i < N; i++) {
        if(str[i] == 'A') AC++;
        else if(str[i] == 'B') BC++;
    }
    int ans = INT_MAX;
    for(int i = 0,curr; i < N; i++) {
        curr = AB+AC;
        if(BA == AB) curr += BC;
        else if(BA > AB) curr += BA-AB+BC;
        else curr += CA-AC+CB;
        ans = min(ans, curr);
        //cout << AB << " " << AC << " " << BC << " " << BA << " " << CA << "\n";
        //cout << curr << "\n";
        if(str[i] == 'B') BA--;
        else if(str[i] == 'C') CA--;
        if(str[(A+i)%N] == 'B') BA++;
        else if(str[(A+i)%N] == 'C') CA++;

        if(str[(A+i)%N] == 'A') AB--;
        else if(str[(A+i)%N] == 'C') CB--;
        if(str[(A+B+i)%N] == 'A') AB++;
        else if(str[(A+B+i)%N] == 'C') CB++;

        if(str[(A+B+i)%N] == 'A') AC--;
        else if(str[(A+B+i)%N] == 'B') BC--;
        if(str[i] == 'A') AC++;
        else if(str[i] == 'B') BC++;
    }


    for(int i = 0; i < N; i++) {
        if(str[i] == 'A') str[i] = 'C';
        else if(str[i] == 'C') str[i] = 'A';
    }
    swap(A,C);
    AB = 0; AC = 0; BA = 0; BC = 0; CA = 0; CB = 0;
    for(int i = 0; i < A; i++) {
        if(str[i] == 'B') BA++;
        else if(str[i] == 'C') CA++;
    }
    for(int i = A; i < A+B; i++) {
        if(str[i] == 'A') AB++;
        else if(str[i] == 'C') CB++;
    }
    for(int i = A+B; i < N; i++) {
        if(str[i] == 'A') AC++;
        else if(str[i] == 'B') BC++;
    }

    for(int i = 0,curr; i < N; i++) {
        curr = AB+AC;
        if(BA == AB) curr += BC;
        else if(BA > AB) curr += BA-AB+BC;
        else curr += CA-AC+CB;
        ans = min(ans, curr);
        //cout << AB << " " << AC << " " << BC << " " << BA << " " << CA << "\n";
        //cout << curr << "\n";
        if(str[i] == 'B') BA--;
        else if(str[i] == 'C') CA--;
        if(str[(A+i)%N] == 'B') BA++;
        else if(str[(A+i)%N] == 'C') CA++;

        if(str[(A+i)%N] == 'A') AB--;
        else if(str[(A+i)%N] == 'C') CB--;
        if(str[(A+B+i)%N] == 'A') AB++;
        else if(str[(A+B+i)%N] == 'C') CB++;

        if(str[(A+B+i)%N] == 'A') AC--;
        else if(str[(A+B+i)%N] == 'B') BC--;
        if(str[i] == 'A') AC++;
        else if(str[i] == 'B') BC++;
    }

    cout << ans << "\n";
    return 0;
}