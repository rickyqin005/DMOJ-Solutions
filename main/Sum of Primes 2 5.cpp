#include <iostream>
using namespace std;
int main() {
    bool isPrime[100001] = {true,true,false};
    int sumArr[100001] = {0};
    for(int i = 2; i <= 100000; i++) {
        for(int j = 2*i; j <= 100000; j += i) {
            isPrime[j] = true;
        }
    }
    for(int i = 1; i <= 100000; i++) {
        if(!isPrime[i]) sumArr[i] = sumArr[i-1] + i;
        else sumArr[i] = sumArr[i-1];
    }
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        int A, B;
        cin >> A >> B;
        cout << sumArr[B]-sumArr[A-1] << "\n";
    }
    return 0;
}