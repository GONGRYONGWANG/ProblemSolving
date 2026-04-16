#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int min(int a, int b, int c) {
	if (a < b) { b = a; }
	if (b < c) { c = b; }
	return c;
}

int dp[1000000];

int DP(int n) {
	if (n == 1) {
		return 0;
	}
	int DP3 = 1000000;
	int DP2 = 1000000;
	int DP1 = 1000000;
	if (dp[n] == 0) {
		if (n % 3 == 0) {
			DP3 = DP(n / 3);
		}
		if (n % 2 == 0) {
			DP2 = DP(n / 2);
		}
		DP1 = DP(n - 1);
		dp[n] = 1 + min(DP1, DP2, DP3);
	}
	return dp[n];
}


int N;

int main() {
	cin >> N;
	cout << DP(N);
}