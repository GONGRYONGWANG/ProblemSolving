#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int lines[501];

int N;

int dp[501][501];
int DP(int idx, int MAX) {
	if (idx == 500) {
		if (lines[idx] > MAX) { return 1; }
		else { return 0; }
	}
	if (lines[idx] == 0) { 
		dp[idx][MAX] = DP(idx + 1, MAX);
		return dp[idx][MAX]; 
	}
	if (dp[idx][MAX] == 0) {
		if (lines[idx] > MAX) {
			dp[idx][MAX] = max({ DP(idx + 1, MAX), 1 + DP(idx + 1, lines[idx]) });
		}
		else if (lines[idx] < MAX) {
			dp[idx][MAX] = DP(idx + 1, MAX);
		}
	}
	return dp[idx][MAX];
}


int main() {
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		cin >> lines[tmp];
	}
	cout << N - DP(1, 0);
}