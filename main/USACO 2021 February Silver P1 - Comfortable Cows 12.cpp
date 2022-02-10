#include<bits/stdc++.h>
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
typedef pair<int, double> pid;
typedef pair<double, int> pdi;
typedef pair<pii, int> piipi;
typedef vector<int> vii;
typedef vector<ll> vll;

#define MAXx 2100
#define MAXy 2100
#define off 550
bool cow[MAXx][MAXy];//offset by (550,550)
bool needed[MAXx][MAXy];
queue<pii> q;
int dir[5][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}, {0,0}};
int cnt = 0;
int check(int x, int y) {
    if((cow[x-1][y] || needed[x-1][y])+(cow[x+1][y] || needed[x+1][y])+(cow[x][y-1] || needed[x][y-1])+(cow[x][y+1] || needed[x][y+1]) == 3) {
        if(!cow[x-1][y] && !needed[x-1][y]) return 1;
        else if(!cow[x+1][y] && !needed[x+1][y]) return 2;
        else if(!cow[x][y-1] && !needed[x][y-1]) return 3;
        else if(!cow[x][y+1] && !needed[x][y+1]) return 4;
    }
    return 0;
}
void addCow(int x, int y) {
    for(int j = 0,chk,newX,newY; j < 5; j++) {
        newX = x+dir[j][0]; newY = y+dir[j][1];
        if(!cow[newX][newY] && !needed[newX][newY]) continue;
        chk = check(newX, newY);
        if(chk == 1) {q.push(mp(newX-1,newY)); needed[newX-1][newY] = true; cnt++;}
        else if(chk == 2) {q.push(mp(newX+1,newY)); needed[newX+1][newY] = true; cnt++;}
        else if(chk == 3) {q.push(mp(newX,newY-1)); needed[newX][newY-1] = true; cnt++;}
        else if(chk == 4) {q.push(mp(newX,newY+1)); needed[newX][newY+1] = true; cnt++;}
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    memset(cow, 0, sizeof(cow));
    memset(needed, 0, sizeof(needed));
    int N; cin >> N;
    for(int i = 0,x,y; i < N; i++) {
        cin >> x >> y;
        x += off; y += off;
        cow[x][y] = true;
        if(needed[x][y]) {
            cnt--;
            needed[x][y] = false;
        } else {
            q.push(mp(x,y));
        }
        while(!q.empty()) {
            pii curr = q.front(); q.pop();
            addCow(curr.f, curr.s);
        }
        cout << cnt << "\n";
    }
    return 0;
}