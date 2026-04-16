#include<iostream>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;
	int N[100];
	for (int i = 65; i <= 90; i++) {
		N[i] = 0;
	}

	for (int i = 0; i < S.length(); i++) {
		if ((int)S[i] < 91) {
			N[(int)S[i]]++;
		}
		else {
			N[(int)S[i] - 32]++;
		}
	}

	int idx = 65;
	int issame = 0;
	for (int i = 66; i <= 90; i++) {
		if (N[i] > N[idx]) { 
			idx = i; 
			issame = 0;
		}
		else if (N[i] == N[idx]) { issame = 1; }
	}
	if (issame) { cout << "?"; }
	else { cout << (char)idx; }
}