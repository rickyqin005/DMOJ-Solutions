#include <bits/stdc++.h>
using namespace std;
int main() {
	int position = 1;
	while(true) {
		int roll; cin >> roll;
		if(roll == 0) {
			cout << "You Quit!" << endl;
			return 0;
		}
		if(position + roll <= 100) position += roll;
		if(position == 9) position = 34;
		else if(position == 40) position = 64;
		else if(position == 54) position = 19;
		else if(position == 67) position = 86;
		else if(position == 90) position = 48;
		else if(position == 99) position = 77;
		cout << "You are now on square " << position << endl;
		if(position == 100) {
			cout << "You Win!" << endl;
			return 0;
		}
	}
	return 0;
}