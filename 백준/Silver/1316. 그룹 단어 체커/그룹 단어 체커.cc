#include<iostream>
#include <string>
using namespace std;

bool isgroupword(string S);

int main() {
	int N;
	cin >> N;
	string S;
	int N2 = N;
	for (int i = 0; i < N2; i++) {
		cin >> S;
		if (!isgroupword(S)) { N--; }
	}
	cout << N;
}

bool isgroupword(string S) {
	int M[123];
	for (int i = 97; i < 123; i++) {
		M[i] = 0;
	}

	int idx = 0;

	while (idx<S.length()) {
		M[(int)S[idx]]++;
		while (idx < S.length()-1 && S[idx] == S[idx + 1]) { 
			idx++; 
		}
		idx++;
	}

	for (int i = 97; i < 123; i++) {
		if (M[i] > 1) { return 0; }
	}
	return 1;
}