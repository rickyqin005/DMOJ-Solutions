#include <iostream>
#include <utility>
#include <unordered_map>
using namespace std;

int main() {
	unordered_map<char,int> symbol;
	symbol['I'] = 1; symbol['V'] = 5; symbol['X'] = 10; symbol['L'] = 50;
	symbol['C'] = 100; symbol['D'] = 500; symbol['M'] = 1000;

	pair<char,int> symbols[7] = {
		make_pair('M',1000), make_pair('D',500), make_pair('C',100),
		make_pair('L',50), make_pair('X',10), make_pair('V',5), make_pair('I',1)
	};
    int N; cin >> N;
    cin.ignore(2,'\n');
    for(int i = 0; i < N; i++) {
    	string str; getline(cin,str);
    	int val1 = 0, val2 = 0;
    	int j = 0;
    	for(; j < str.length(); j++) {
    		if(str[j] == '+') break;
    		int curr = symbol[str[j]], next = symbol[str[j+1]];
    		if(next > curr) val1 -= curr;
    		else val1 += curr;
    	}
    	for(j += 1; j < str.length(); j++) {
    		if(str[j] == '=') break;
    		int curr = symbol[str[j]], next = symbol[str[j+1]];
			if(next > curr) val2 -= curr;
			else val2 += curr;
		}
    	cout << str;
    	int sum = val1+val2;
    	if(sum > 1000) cout << "CONCORDIA CUM VERITATE" << endl;
    	else if(sum == 1000) cout << 'M' << endl;
    	else {
    		int digit[3] = {sum/100,sum/10%10,sum%10};
    		for(int j = 0; j < 3; j++) {
    			if(digit[j] == 0) continue;
    			if(digit[j] >= 5) {
    				if(digit[j] == 9) cout << symbols[2*(j+1)].first << symbols[2*j].first;
    				else cout << symbols[2*j+1].first << string(digit[j]-5,symbols[2*(j+1)].first);
    			} else {
    				if(digit[j] == 4) cout << symbols[2*(j+1)].first << symbols[2*j+1].first;
    				else cout << string(digit[j],symbols[2*(j+1)].first);
    			}
    		}
    		cout << endl;
    	}
    }
}