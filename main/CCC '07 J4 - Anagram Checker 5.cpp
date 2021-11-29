#include <bits/stdc++.h>
using namespace std;
int main() {
	string str1, str2;
	getline(cin,str1);
	getline(cin,str2);
	int arrFreq1[26] = {0};
	int arrFreq2[26] = {0};
	for(int i = 0; i < str1.length(); i++) {
		if(str1.at(i) == ' ') continue;
		arrFreq1[str1.at(i)-65]++;
	}
	for(int i = 0; i < str2.length(); i++) {
		if(str2.at(i) == ' ') continue;
		arrFreq2[str2.at(i)-65]++;
	}
	for(int i = 0; i < 26; i++) {
		if(arrFreq1[i] != arrFreq2[i]) {
			cout << "Is not an anagram." << endl;
			return 0;
		}
	}
	cout << "Is an anagram." << endl;
	return 0;
}