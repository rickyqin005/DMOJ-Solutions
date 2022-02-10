#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;
int gcd_max(int a, int b) {return ((b == 0) ? a : gcd_max(b, a%b));}
int gcd(int a, int b) {return gcd_max(max(a,b),min(a,b));}
#define MAXN 100000
#define MAXST (1 << 18)// 2^18
int N,M,minp;
int st[MAXST+1];
int st2[MAXST+1];
int q[MAXST+1];

void buildST() {
    for(int i = minp; i < minp+N; i++) {
        cin >> st[i]; st2[i] = st[i];
        q[i] = 1;
    }
    memset(st+minp+N, 0x7f, sizeof(st[0])*(minp-N));
    for(int i = minp-1; i > 0; i--) {
        if(st[2*i] < st[2*i+1]) {
            st[i] = st[2*i];
            q[i] = q[2*i];
        } else if(st[2*i] > st[2*i+1]) {
            st[i] = st[2*i+1];
            q[i] = q[2*i+1];
        } else {
            st[i] = st[2*i];
            q[i] = q[2*i]+q[2*i+1];
        }
        st2[i] = gcd(st2[2*i],st2[2*i+1]);
    }
}
void update(int idx, int val) {
    idx += minp-1;
    st[idx] = st2[idx] = val;
    idx >>= 1;
    while(idx > 0) {
        if(st[2*idx] < st[2*idx+1]) {
            st[idx] = st[2*idx];
            q[idx] = q[2*idx];
        } else if(st[2*idx] > st[2*idx+1]) {
            st[idx] = st[2*idx+1];
            q[idx] = q[2*idx+1];
        } else {
            st[idx] = st[2*idx];
            q[idx] = q[2*idx]+q[2*idx+1];
        }
        st2[idx] = gcd(st2[2*idx],st2[2*idx+1]);
        idx >>= 1;
    }
}
int querySt(int idx, int s, int e, int l, int r) {
    if(e < l || s > r) return INT_MAX;
    else if(s >= l && e <= r) return st[idx];
    return min(querySt(idx*2,s,(s+e)/2,l,r),querySt(idx*2+1,(s+e)/2+1,e,l,r));
}
int querySt2(int idx, int s, int e, int l, int r) {
    if(e < l || s > r) return 0;
    else if(s >= l && e <= r) return st2[idx];
    return gcd(querySt2(idx*2,s,(s+e)/2,l,r), querySt2(idx*2+1,(s+e)/2+1,e,l,r));
}
int queryQ(int idx, int g, int s, int e, int l, int r) {
    if(e < l || s > r) return 0;
    else if(s >= l && e <= r) {
        if(st[idx] == g) return q[idx];
        return 0;
    }
    return queryQ(idx*2,g,s,(s+e)/2,l,r) + queryQ(idx*2+1,g,(s+e)/2+1,e,l,r);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(st, 0, sizeof(st));
    memset(st2, 0, sizeof(st2));
    memset(q, 0, sizeof(q));
    cin >> N >> M;
    minp = (1 << (31-clz((N-1) << 1)));
    buildST();

    char chr; int x,v,l,r;
    for(int i = 0; i < M; i++) {
        cin >> chr;
        if(chr == 'C') {
            cin >> x >> v;
            update(x, v);
        } else if(chr == 'M') {
            cin >> l >> r;
            cout << querySt(1,1,minp,l,r) << "\n";
        } else if(chr == 'G') {
            cin >> l >> r;
            cout << querySt2(1,1,minp,l,r) << "\n";
        } else {
            cin >> l >> r;
            cout << queryQ(1,querySt2(1,1,minp,l,r),1,minp,l,r) << "\n";
        }
    }
    return 0;
}