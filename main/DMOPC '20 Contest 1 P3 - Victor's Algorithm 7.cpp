#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    int arr[N];
    int maxPeak = -1000000001;
    int maxPeakIndex = 0;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr[i] = num;
        if(num >= maxPeak) {
            maxPeak = num;
            maxPeakIndex = i;
        }
    }
    long long int cost = 0;
    for(int i = 1; i < maxPeakIndex; i++) {
        if(arr[i] < arr[i-1]) {
            int increment = arr[i-1]-arr[i];
            arr[i] += increment;
            cost += increment;
        }
    }

    for(int i = N-2; i > maxPeakIndex; i--) {
        if(arr[i] < arr[i+1]) {
            int increment = arr[i+1]-arr[i];
            arr[i] += increment;
            cost += increment;
        }
    }

    cout << cost << "\n";
    return 0;
}