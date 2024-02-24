#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#define endl "\n"
using namespace std;



string S;


int main() {
	cin >> S;
	S += "E";
	int total = 0;
	int tmp=0;
	bool state = 1;
	for (int i = 0; i < S.length()+1; i++) {
		if (isdigit(S[i])) {  
			tmp = tmp * 10 + (S[i]-48); 
		}
		else {
			if (state ==1) { // +
				if (S[i] == '-') { state = 0; }
				total += tmp;
				tmp = 0;
			}
			else { // -
				total -= tmp;
				tmp = 0;
			}
		}
	}
	cout << total;

}