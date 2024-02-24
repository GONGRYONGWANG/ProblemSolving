#include<iostream>
#include<string>
using namespace std;
#define endl "\n"

bool isVPS(string S) {
	int o = 0;
	int c = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '(') { o++; }
		else { c++; }
		if (c > o) { return 0; }
	}
	if (c == o) { return 1; }
	return 0;
}

int main() {
	int T;
	cin >> T;
	string S;
	for (int i = 0; i < T; i++) {
		cin >> S;
		if (isVPS(S)) {
			cout << "YES";
		}
		else { cout << "NO"; }
		cout << endl;
	}
}