#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int seq[1001];
int N;

long long dp[1001][1001];
int DP(int idx, int MAX) {
	if (idx == N) {
		if (seq[idx] > MAX) { return seq[idx]; }
		else { return 0; }
	}
	if (dp[idx][MAX] == 0) {
		if (MAX >= seq[idx]) {
			dp[idx][MAX] = DP(idx + 1, MAX);
		}
		else if (MAX < seq[idx]) {
			dp[idx][MAX] = max({ seq[idx] + DP(idx + 1, seq[idx]), DP(idx + 1, MAX) });
		}
	}
	return dp[idx][MAX];
}


int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> seq[i];
	}
	cout << DP(1, 0);
}
