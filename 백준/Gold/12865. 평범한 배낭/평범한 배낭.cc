#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
#define endl "\n"

int N;
int K;
int W[100];
int V[100];

int dp[100][100001];
int DP(int idx, int k) {
	if (idx == N) {
		return 0;
	}

	int tmp1, tmp2;
	if (dp[idx][k] == -1) {
		if (W[idx] <= k) {

			tmp1 = V[idx] + DP(idx + 1, k - W[idx]);
			tmp2 = DP(idx + 1, k);

			if (tmp1 > tmp2) { dp[idx][k] = tmp1; }
			else { dp[idx][k] = tmp2; }
		}

		else if (W[idx] > k) {
			dp[idx][k] = DP(idx + 1, k);
		}
	}
	return dp[idx][k];
}



int main() {
	cin >> N;
	cin >> K;
	for (int i = 0; i < N; i++) {
		cin >> W[i] >> V[i];
		for (int j = 0; j <= K; j++) {
			dp[i][j] = -1;
		}
	}
	cout << DP(0, K);
}