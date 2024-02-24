#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define endl "\n"

int dp[500][500];
vector<int> pages;

int DP(int a, int b) {
	if (a == b) { return 0; }
	if (dp[a][b] != 0) {
		return dp[a][b];
	}

	int result;
	result = DP(a + 1, b);
	int tmp;
	for (int i = a; i < b - 1; i++) {
		tmp = DP(a, i+1) + DP(i+2, b);
		if (tmp < result) {
			result = tmp;
		}
	}
	for (int i = a; i < b+1; i++) {
		result += pages[i];
	}
	dp[a][b] = result;
	return result;
}

void run() {
	int K;
	pages.clear();
	int tmp;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> tmp;
		pages.push_back(tmp);
		for (int j = 0; j < K; j++) {
			dp[i][j] = 0;
		}
	}
	cout << DP(0, K - 1)<<endl;




	return;
}


int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		run();
	}
	return 0;
}