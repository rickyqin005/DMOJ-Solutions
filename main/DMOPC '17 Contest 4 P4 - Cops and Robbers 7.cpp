#include <iostream>
#include <unordered_set>
using namespace std;
int main() {
    int N;
    cin >> N;
    unordered_set <int> guardSet;
    int order[N] = {0};
    int prev = 0;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if(guardSet.find(num) == guardSet.end()) {
            guardSet.insert(num);
            if(prev != 0) order[i] = prev;
			prev = num;
        }
    }
    order[0] = prev;
    if(guardSet.size() == 1) cout << -1;
    else {
        int currBank = 1;
        for(int i = 0; i < N; i++) {
            if(order[i] == 0) {
                while(guardSet.find(currBank) != guardSet.end()) currBank++;
                order[i] = currBank;
                currBank++;
            }
            cout << order[i];
            if(i == N-1) cout << "\n";
            else cout << " ";
        }
    }
    return 0;
}