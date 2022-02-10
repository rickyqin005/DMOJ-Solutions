#include <bits/stdc++.h>
using namespace std;
int main() {
	char vowel[5] = {'a','e','i','o','u'};
	string str; cin >> str;
	for(int i = 0; i < str.length(); i++) {
		char letter = str.at(i);
		cout << letter;
		switch(letter) {
		case 'a': case 'e': case 'i': case 'o': case 'u':
			break;
		default:
			int closestVowel = 97;
			for(int j = 0; j < 5; j++) {
				if(abs(letter-vowel[j]) < abs(letter-closestVowel)) {
					closestVowel = vowel[j];
				}
			}
			cout << (char)closestVowel;
			if(letter == 'z') cout << 'z';
			else {
				if(letter+1 == closestVowel) cout << (char)(closestVowel+1);
				else cout << (char)(letter+1);
			}
		}
	}
	cout << endl;
	return 0;
}