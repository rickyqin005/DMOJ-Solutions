#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T_val, class T_inc> struct binary_indexed_tree_2d {
private: vector<vector<T_val>> bit;
public:
    int R,C;
    void set_range(int r, int c) {
        R = r; C = c;
    }
    binary_indexed_tree_2d(int r, int c) {
        set_range(r,c);
        bit = vector<vector<T_val>>(r+1, vector<T_val>(c+1));
    }
    void bld() {
        for(int i = 1; i <= R; i++) {
            for(int pow = 2,gap = 1; pow <= C; pow <<= 1,gap <<= 1) {
                for(int j = pow; j <= C; j += pow) bit[i][j] += bit[i][j-gap];
            }
        }
        for(int j = 1; j <= C; j++) {
            for(int pow = 2,gap = 1; pow <= R; pow <<= 1,gap <<= 1) {
                for(int i = pow; i <= R; i += pow) bit[i][j] += bit[i-gap][j];
            }
        }
    }
    void build(istream &in = cin) {
        for(int i = 1; i <= R; i++) {
            for(int j = 1; j <= C; j++) in >> bit[i][j];
        }
        bld();
    }
    void reset() {
        for(int i = 1; i <= R; i++) fill(bit[i].begin(), bit[i].end(), 0);
    }
    void increment(int r, int c, T_inc inc) {
        for(; r <= R; r += r&-r) {
            for(int col = c; col <= C; col += col&-col) bit[r][col] += inc;
        }
    }
    T_val qry(int r, int c) {
        T_val ans = 0;
        for(; r; r ^= r&-r) {
            for(int col = c; col; col ^= col&-col) ans += bit[r][col];
        }
        return ans;
    } T_val query(int r1, int r2, int c1, int c2) {return qry(r2,c2) - qry(r1-1,c2) - qry(r2,c1-1) + qry(r1-1,c1-1);}
    void print(ostream &out = cout) {
        for(int i = 1; i <= R; i++) {
            for(int j = 1; j <= C; j++) out << bit[i][j] << " ";
            out << "\n";
        }
    }
};
binary_indexed_tree_2d<int, int> bit(1024,1024);
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N; cin >> N >> N;
    bit.set_range(N,N);
    int I,x,y,a,l,b,r,t;
    while(true) {
        cin >> I;
        if(I == 1) {
            cin >> x >> y >> a; x++; y++;
            bit.increment(x,y,a);
        } else if(I == 2) {
            cin >> l >> b >> r >> t; l++; b++; r++; t++;
            cout << bit.query(l,r,b,t) << "\n";
        } else break;
    }
    return 0;
}