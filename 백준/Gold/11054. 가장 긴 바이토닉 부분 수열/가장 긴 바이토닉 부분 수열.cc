#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int N;
int seq[1001];
int dp[1001][2][1001];
int DP(int idx, int type, int Mm) {
	if (idx == N) {
		if (type == 0 && seq[idx] != Mm) { return 1; }
		if (type == 1 && seq[idx] < Mm) { return 1; }
		return 0;
	}


	if (dp[idx][type][Mm] == 0) {
		if (type == 1) {
			if (seq[idx] >= Mm) {
				dp[idx][type][Mm] = DP(idx + 1, type, Mm);
			}
			else if (seq[idx] < Mm) {
				dp[idx][type][Mm] = max({ 1 + DP(idx + 1, type, seq[idx]), DP(idx + 1,type, Mm) });
			}
		}
		else if (type == 0) {
			if (seq[idx] == Mm) {
				dp[idx][type][Mm] = DP(idx + 1, type, Mm);
			}
			else if (seq[idx] < Mm) {
				dp[idx][type][Mm] = max({ DP(idx + 1, type, Mm), 1 + DP(idx + 1, type + 1, seq[idx]) });
			}
			else if (seq[idx] > Mm) {
				dp[idx][type][Mm] = max({ 1 + DP(idx + 1, type, seq[idx]), DP(idx + 1, type, Mm) });
			}
		}
	}
	return dp[idx][type][Mm];
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> seq[i];
	}
	cout << DP(1, 0, 0);
}