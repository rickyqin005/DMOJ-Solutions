#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long
#define pb push_back
int main() {
    string str; cin >> str;
    int N = str.size();
    int countL = 0, countM = 0, countS = 0;
    for(int i = 0; i < N; i++) {
        if(str[i] == 'L') countL++;
        else if(str[i] == 'M') countM++;
        else countS++;
    }
    int section[3][3];
    memset(section, 0, sizeof(section));
    for(int i = 0; i < countL; i++) {
        if(str[i] == 'L') section[0][0]++;
        else if(str[i] == 'M') section[0][1]++;
        else section[0][2]++;
    }
    for(int i = countL; i < countL+countM; i++) {
        if(str[i] == 'L') section[1][0]++;
        else if(str[i] == 'M') section[1][1]++;
        else section[1][2]++;
    }
    for(int i = countL+countM; i < N; i++) {
        if(str[i] == 'L') section[2][0]++;
        else if(str[i] == 'M') section[2][1]++;
        else section[2][2]++;
    }
    int ans = 0;

    int num = min(section[0][1], section[1][0]);
    ans += num;
    section[0][0] += num;
    section[0][1] -= num;
    section[1][1] += num;
    section[1][0] -= num;

    num = min(section[0][2], section[2][0]);
    ans += num;
    section[0][0] += num;
    section[0][2] -= num;
    section[2][2] += num;
    section[2][0] -= num;

    num = min(section[1][2], section[2][1]);
    ans += num;
    section[1][1] += num;
    section[1][2] -= num;
    section[2][2] += num;
    section[2][1] -= num;

    num = section[1][0];
    ans += num;
    section[0][0] += num;
    section[0][2] -= num;
    section[1][0] -= num;
    section[1][2] += num;

    num = section[2][0];
    ans += num;
    section[0][0] += num;
    section[0][1] -= num;
    section[2][0] -= num;
    section[2][1] += num;

    num = section[1][2];
    ans += num;
    section[2][2] += num;
    section[2][1] -= num;
    section[1][2] -= num;
    section[1][1] += num;

    cout << ans << "\n";
    return 0;
}