#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
#define clz __builtin_clz
typedef long long ll;
typedef pair<int, int> pii;
#define MAX_BLOCK 388
pii arr[150001];
int numshift[150001];// # of shifts for each line
int blksum[MAX_BLOCK+1];// # of people in each block
int numtrainblk[MAX_BLOCK+1][150001];// [block #][line #] = # stations
vector<int> route[150001];// station numbers for each line
vector<int> trainppl[150001];// # of people in each train for each line
inline int get_idx(int idx, int N) {return (idx-1+3*N)%N + 1;}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(numshift, 0, sizeof(numshift));
    memset(blksum, 0, sizeof(blksum));
    memset(numtrainblk, 0, sizeof(numtrainblk));
    int N,M,Q; cin >> N >> M >> Q;
    const int blklen = ceil(sqrt(N));
    const int numblk = ceil((double)N/blklen);
    //cout << "block length = " << blklen << ", # of blocks = " << numblk << endl;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i].f;
        route[arr[i].f].pb(i);
        arr[i].s = route[arr[i].f].size();
    }
    for(int i = 1,p; i <= N; i++) {
        cin >> p;
        trainppl[arr[i].f].pb(p);
    }
    for(int i = 1; i <= numblk; i++) {
        int bl = ((i-1)*blklen+1), br = min(i*blklen, N);
        for(int j = bl; j <= br; j++) numtrainblk[i][arr[j].f]++;
        for(int j = bl; j <= br; j++) blksum[i] += trainppl[arr[j].f][arr[j].s-1];
    }
    //cout << "ppl: "; for(int i = 1; i <= numblk; i++) {cout << blksum[i] << " ";} cout << endl;
    for(int i = 1,t,l,r,x; i <= Q; i++) {
        cin >> t;
        if(t == 1) {
            cin >> l >> r;
            int ans = 0;
            for(int j = 1; j <= numblk; j++) {
                int bl = ((j-1)*blklen+1), br = min(j*blklen, N);// [((j-1)*blklen+1), j*blklen]
                if(l <= bl && br <= r) ans += blksum[j];
                else {// beginning or ending block
                    for(int k = max(bl,l); k <= min(br, r); k++) {
                        // arr[k].f = line number for train k
                        ans += trainppl[arr[k].f][get_idx(arr[k].s - numshift[arr[k].f], route[arr[k].f].size())-1];
                    }
                }
            }
            cout << ans << "\n";
        } else {
            cin >> x;
            int sumleft = 0;// # of trains on line to the left
            for(int j = 1; j <= blklen; j++) {
                if(numtrainblk[j][x] == 0) continue;
                blksum[j] -= trainppl[x][get_idx(sumleft + numtrainblk[j][x] - numshift[x], route[x].size())-1];
                blksum[j] += trainppl[x][get_idx(sumleft - numshift[x], route[x].size())-1];
                sumleft += numtrainblk[j][x];
            }
            numshift[x]++;
            if(numshift[x] == route[x].size()) numshift[x] = 0;
            //cout << "ppl: "; for(int j = 1; j <= numblk; j++) {cout << blksum[j] << " ";} cout << endl;
        }
    }
    return 0;
}
