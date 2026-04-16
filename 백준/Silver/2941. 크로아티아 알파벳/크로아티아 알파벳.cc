#include<iostream>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;

	int wordsnum = S.length();
	for (int i = 1; i < S.length(); i++) {
		if (S[i] == '=') {
			wordsnum--;
			if (i > 1 && S[i - 1] == 'z' && S[i - 2] == 'd') { wordsnum--; }
		}
		if (S[i] == '-') { wordsnum--; }
		if (S[i] == 'j' && S[i - 1] == 'l') { wordsnum--; }
		if (S[i] == 'j' && S[i - 1] == 'n') { wordsnum--; }
	}
	cout << wordsnum;
}