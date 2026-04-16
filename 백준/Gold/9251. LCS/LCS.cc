#include<iostream>
using namespace std;
#include<string>

int max(int a, int b) {
	if (a > b) { return a; }
	return b;
}

string A, B;

int lcs[1000][1000];

int LCS(int idx1 = 0, int idx2 = 0) {
	if (idx1 == A.length() || idx2 == B.length()) { return 0; }
	if (lcs[idx1][idx2] != -1);
	else if (A[idx1] == B[idx2]) {
		lcs[idx1][idx2] = 1+ LCS(idx1 + 1, idx2 + 1);
	}
	else {
		lcs[idx1][idx2] = max(LCS(idx1 + 1, idx2), LCS(idx1, idx2 + 1));
	}
	return lcs[idx1][idx2];
}

int main() {
	cin >> A >> B;
	for (int i = 0; i < A.length(); i++) {
		for (int j = 0; j < B.length(); j++) {
			lcs[i][j] = -1;
		}
	}
	cout << LCS();
}