#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD1 9999999900000001//1e16
#define MOD2 9999991111111//1e13
#define BASE1 31
#define BASE2 200003
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
ll pow1[200000];//substr
ll pow2[26];//freq
unordered_set<ll> subStr;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    string strN,strH; cin >> strN >> strH;
    int N = strN.length(), H = strH.length();
    if(N > H) {cout << 0 << "\n"; return 0;}
    pow1[0] = pow2[0] = 1;
    for(int i = 1; i < H; i++) pow1[i] = (pow1[i-1]*BASE1)%MOD1;
    for(int i = 1; i < 26; i++) pow2[i] = (pow2[i-1]*BASE2)%MOD2;
    ll hashN2 = 0;//N2: freq
    ll hashH1 = 0, hashH2 = 0;//H1: substr, H2: freq
    for(int i = 0; i < N; i++) hashN2 = (hashN2+pow2[strN[i]-'a'])%MOD2;

    for(int i = 0; i < N-1; i++) {
        hashH1 = (hashH1+(strH[i]-'a')*pow1[(N-1)-i])%MOD1;
        hashH2 = (hashH2+pow2[strH[i]-'a'])%MOD2;
    }
    for(int i = N-1; i < H; i++) {
        hashH1 = (hashH1+(strH[i]-'a')/*pow1[0]*/)%MOD1;
        hashH2 = (hashH2+pow2[strH[i]-'a'])%MOD2;
        //cout << hashH1 << " " << hashH2 << "\n";

        if(hashN2 == hashH2) subStr.insert(hashH1);
        hashH1 = (hashH1-(strH[i-(N-1)]-'a')*pow1[N-1]+MOD1*100LL)%MOD1;
        hashH1 = (hashH1*BASE1)%MOD1;
        hashH2 = (hashH2-pow2[strH[i-(N-1)]-'a']+MOD2)%MOD2;
    }
    cout << subStr.size() << "\n";
    return 0;
}