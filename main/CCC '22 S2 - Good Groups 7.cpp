#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define mp make_pair
typedef pair<int, int> pii;
typedef pair<string, string> pss;
pss arr1[100001];
pss arr2[100001];
unordered_map<string, unordered_set<string>> map1;
unordered_map<string, unordered_set<string>> map2;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int X; cin >> X;
    string str1, str2, str3;

    for(int i = 1; i <= X; i++) {
        cin >> str1 >> str2;
        map1[str1].insert(str2);
    }
    int Y; cin >> Y;
    for(int i = 1; i <= Y; i++) {
        cin >> str1 >> str2;
        map2[str1].insert(str2);
    }
    int G; cin >> G;
    int ans = 0;
    for(int i = 1; i <= G; i++) {
        cin >> str1 >> str2 >> str3;
        map1[str1]; map2[str1];
        map1[str2]; map2[str2];
        map1[str3]; map2[str3];
        
        int num = map1[str1].size();
        if(map1[str1].find(str2) != map1[str1].end()) num--;
        if(map1[str1].find(str3) != map1[str1].end()) num--;
        ans += num;

        num = map1[str2].size();
        if(map1[str2].find(str1) != map1[str2].end()) num--;
        if(map1[str2].find(str3) != map1[str2].end()) num--;
        ans += num;

        num = map1[str3].size();
        if(map1[str3].find(str1) != map1[str3].end()) num--;
        if(map1[str3].find(str2) != map1[str3].end()) num--;
        ans += num;

        if(map2[str1].find(str2) != map2[str1].end()) ans++;
        if(map2[str1].find(str3) != map2[str1].end()) ans++;

        if(map2[str2].find(str1) != map2[str2].end()) ans++;
        if(map2[str2].find(str3) != map2[str2].end()) ans++;

        if(map2[str3].find(str1) != map2[str3].end()) ans++;
        if(map2[str3].find(str2) != map2[str3].end()) ans++;
    }
    
    cout << ans << "\n";
    return 0;
}