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
template<class T_val, class T_inc> struct binary_indexed_tree {
private: vector<T_val> bit;
public:
    int N;
    void resize(int n) {N = n;}
    binary_indexed_tree(int cap) {
        N = cap;
        bit = vector<T_val>(cap+1);
    }
    void add(int i, T_inc inc) {
        for(; i <= N; i += i&-i) bit[i] += inc;
    }
    T_val qry(int r) {
        T_val ans = 0;
        for(; r; r ^= r&-r) ans += bit[r];
        return ans;
    } T_val query(int l, int r) {return qry(r)-qry(l-1);}
    void print(ostream &out = cout) {
        for(int i = 1; i <= N; i++) {out << bit[i] << " ";} out << "\n";
    }
};
struct hline {int y,x1,x2; hline(int Y, int X1, int X2){y = Y; x1 = X1; x2 = X2;} hline(){}};
struct vline {int x,y1,y2; vline(int X, int Y1, int Y2){x = X; y1 = Y1; y2 = Y2;} vline(){}};
hline inh[5001];
vline inv[5001];
vector<int> idxX, idxY;
vector<hline> hori[15001];//group horizontal lines by y-coordinate
vector<vline> vert[15001];//group vertical lines by bottom y-coordinate
binary_indexed_tree<int, int> bit(15000);
binary_indexed_tree<int, int> bitSubtract(15000);//accounts for vertical lines with the same x-coordinate
int XFreq[15001];//number of vertical lines in the BIT for each x-coordinate
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int H,V; cin >> H >> V;
    for(int i = 1; i <= H; i++) {
        cin >> inh[i].y >> inh[i].x1 >> inh[i].x2;
        idxY.pb(inh[i].y);
        idxX.pb(inh[i].x1);
        idxX.pb(inh[i].x2);
    }
    for(int i = 1; i <= V; i++) {
        cin >> inv[i].x >> inv[i].y1 >> inv[i].y2;
        idxX.pb(inv[i].x);
        idxY.pb(inv[i].y1);
        idxY.pb(inv[i].y2);
    }
    //map the current coordinates to the new compressed coordinates
    sort(idxX.begin(), idxX.end());
    sort(idxY.begin(), idxY.end());
    idxX.erase(unique(idxX.begin(), idxX.end()), idxX.end());
    idxY.erase(unique(idxY.begin(), idxY.end()), idxY.end());
    int X = idxX.size(), Y = idxY.size();
    for(int i = 1; i <= H; i++) {
        inh[i].y = Y-(lower_bound(idxY.begin(), idxY.end(), inh[i].y)-idxY.begin());
        inh[i].x1 = lower_bound(idxX.begin(), idxX.end(), inh[i].x1)-idxX.begin()+1;
        inh[i].x2 = lower_bound(idxX.begin(), idxX.end(), inh[i].x2)-idxX.begin()+1;
        hori[inh[i].y].pb(hline(inh[i]));
    }
    for(int i = 1; i <= V; i++) {
        inv[i].x = lower_bound(idxX.begin(), idxX.end(), inv[i].x)-idxX.begin()+1;
        inv[i].y1 = Y-(lower_bound(idxY.begin(), idxY.end(), inv[i].y1)-idxY.begin());
        inv[i].y2 = Y-(lower_bound(idxY.begin(), idxY.end(), inv[i].y2)-idxY.begin());
        swap(inv[i].y1, inv[i].y2);
        vert[inv[i].y2].pb(vline(inv[i]));
    }
    //for each horizontal line, run line sweep downwards from that line
    memset(XFreq, 0, sizeof(XFreq));
    ll ans = 0;
    bit.resize(X);
    for(int i = 1; i < Y; i++) {
        for(hline hlinei: hori[i]) {
            int BITcnt = 0;
            for(int j = i+1; j <= Y; j++) {
                for(vline linev: vert[j]) {
                    //if the vertical line intersects hlinei, add it to the BIT
                    if(linev.y1 <= hlinei.y && hlinei.x1 <= linev.x && linev.x <= hlinei.x2) {
                        bit.add(linev.x,1);
                        BITcnt++;
                        XFreq[linev.x]++;
                        bitSubtract.add(linev.x, XFreq[linev.x]-1);
                    }
                }
            }
            for(int j = i+1; j <= Y && BITcnt > 0; j++) {
                for(hline hlinej: hori[j]) {
                    //when we reach another horizontal line, query the overlap of the lines
                    if(!(hlinej.x2 <= hlinei.x1 || hlinei.x2 <= hlinej.x1)) {
                        int n = bit.query(max(hlinei.x1, hlinej.x1), min(hlinei.x2, hlinej.x2));
                        ans += n*(n-1)/2 - bitSubtract.query(max(hlinei.x1, hlinej.x1), min(hlinei.x2, hlinej.x2));
                    }
                }
                for(vline linev: vert[j]) {
                    //if the vertical line that intersected hlinei ends, remove it from the BIT
                    if(linev.y1 <= hlinei.y && hlinei.x1 <= linev.x && linev.x <= hlinei.x2) {
                        bit.add(linev.x,-1);
                        BITcnt--;
                        bitSubtract.add(linev.x, -(XFreq[linev.x]-1));
                        XFreq[linev.x]--;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}