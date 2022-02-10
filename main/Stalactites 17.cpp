#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807
#define MOD 1000000007
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piipi;
int N, Q;
int len[251][251][251];
ll bit[251][251][251];
ll qry(int x, int y, int z) {
    ll ans = 0, px = 1,py,ny,pz,nz;
    while(x > 0) {
        if((x&px) == px) {
            ny = y; py = 1;
            while(ny > 0) {
                if((ny&py) == py) {
                    nz = z; pz = 1;
                    while(nz > 0) {
                        if((nz&pz) == pz) {
                            ans += bit[x][ny][nz];
                            nz ^= pz;
                        }
                        pz <<= 1;
                    }
                    ny ^= py;
                }
                py <<= 1;
            }
            x ^= px;
        }
        px <<= 1;
    }
    return ans;
}
ll query(int x1, int y1, int z1, int x2, int y2, int z2) {
    return qry(x2,y2,z2)-qry(x2,y1-1,z2)-qry(x2,y2,z1-1)+qry(x2,y1-1,z1-1)-qry(x1-1,y2,z2)+qry(x1-1,y1-1,z2)+qry(x1-1,y2,z1-1)-qry(x1-1,y1-1,z1-1);
}
void update(int x, int y, int z, int inc) {
    int ny,nz;
    while(x <= N) {
        ny = y;
        while(ny <= N) {
            nz = z;
            while(nz <= N) {
                bit[x][ny][nz] += inc;
                nz += nz & -nz;
            }
            ny += ny & -ny;
        }
        x += x & -x;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(len, 0, sizeof(len));
    memset(bit, 0, sizeof(bit));
    cin >> N >> Q;
    char t; ll ans = 0;
    for(int i = 0,x1,y1,z1,x2,y2,z2,x,y,z,l; i < Q; i++) {
        cin >> t;
        if(t == 'C') {
            cin >> x >> y >> z >> l;
            update(x,y,z,l-len[x][y][z]);
            len[x][y][z] = l;
        } else {
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            ans += query(x1,y1,z1,x2,y2,z2);
        }
    }
    cout << ans << "\n";
    return 0;
}