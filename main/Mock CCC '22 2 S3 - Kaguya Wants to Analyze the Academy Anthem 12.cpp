#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 255455445544554553
#define BASE 29
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, pii> pspii;
string str; int N;
pspii query[200001];// mp(string, mp(k, query number))
int ans[200001];
bool comp(pspii &a, pspii &b) {return a.f.length() < b.f.length();}
ll strhash[200001];
ll pow1[200001];
void calculate_sub_hash(int len) {
    ll val = 0;
    for(int i = 0; i < len-1; i++) val = (val + (str[i]-'a')*pow1[len-1-i])%MOD;
    for(int i = len-1; i < N; i++) {
        val = (val+(str[i]-'a'))%MOD;
        strhash[i] = val;
        val = (val - ((str[i-len+1]-'a')*pow1[len-1])%MOD + MOD)%MOD;
        val = (val*BASE)%MOD;
    }
}
ll get_hash(string &st) {
    ll ans = 0;
    for(int i = 0; i < st.length(); i++) ans = (ans+(st[i]-'a')*pow1[st.length()-1-i])%MOD;
    return ans;
}

//unordered_map<ll, int> umap1;// hash -> # occurances
unordered_map<ll, pair<int, unordered_map<int, vector<int>>>> umap;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(ans, -1, sizeof(ans));
    cin >> str; N = str.length();
    int Q; cin >> Q;
    for(int i = 1; i <= Q; i++) {
        cin >> query[i].f >> query[i].s.f;
        query[i].s.s = i;
    }
    sort(query+1, query+Q+1, comp);
    //for(int i = 1; i <= Q; i++) {cout << query[i].f << " " << query[i].s.f << " " << query[i].s.s << "\n";}
    pow1[0] = 1;
    for(int i = 1; i <= N; i++) pow1[i] = (pow1[i-1]*BASE)%MOD;
    for(int i = 1; i <= Q;) {
        if(query[i].f.length() > N) break;
        umap.clear();
        int len = query[i].f.length();
        calculate_sub_hash(len);
        int r = i+1;// [i, r)
        while(r <= Q && query[r].f.length() == len) r++;
        for(int j = i; j < r; j++) umap[get_hash(query[j].f)].s[query[j].s.f].pb(query[j].s.s);
        for(int j = len-1; j < N; j++) {
            auto it1 = umap.find(strhash[j]);
            if(it1 == umap.end()) continue;
            int freq = (it1->s.f++)+1;
            if(it1->s.s.find(freq) != it1->s.s.end()) {
                for(int idx: it1->s.s[freq]) ans[idx] = j-len+2;
            }
        }
        i = r;
    }
    for(int i = 1; i <= Q; i++) cout << ans[i] << "\n";
    return 0;
}