#include <iostream>
#include <string>
using namespace std;
int main() {
	int M, N, S;
	cin >> M >> N >> S;
	cin.ignore(100,'\n');
	long long int sum = 0;
	for(int i = 1; i <= M; i++) {
		string str;
		getline(cin,str);
		for(int j = 1; j <= N; j++) {
			if(str.at(j-1) == 'X') {
				int mini = min(min(min(i,M-i+1),S),M-S+1);
				int minj = min(min(min(j,N-j+1),S),N-S+1);
				int freq = min(mini*minj,(M-mini+1)*minj);
				freq = min(freq,(N-minj+1)*mini);
				freq = min(freq,(M-mini+1)*(N-minj+1));
				sum += freq;
				//cout << freq << " ";
			}
		}
		//cout << endl;
	}
	printf("%.8f\n",(double)sum/((M-S+1)*(N-S+1)));
	return 0;
}