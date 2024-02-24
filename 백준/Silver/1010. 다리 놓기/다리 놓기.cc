#include<iostream>
using namespace std;
#define endl "\n"


long long ComB[31][31];

long long combination(int n, int r) {
	if (r == 0) { return 1; }
	if (r == 1) { return n; }
	if (n == r) { return 1; }
	long long result = 0;
	if (ComB[n][r] != 0) {
		return ComB[n][r];
	}
	if (ComB[n - 1][r] == 0) {
		ComB[n - 1][r] = combination(n - 1, r);
	}
	if (ComB[n - 1][r - 1] == 0) {
		ComB[n - 1][r - 1] = combination(n - 1, r - 1);
	}
	return ComB[n - 1][r - 1] + ComB[n - 1][r];
}



int main() {
	int T, N, M;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		cout << combination(M, N)<<endl;
	}
	return 0;
}