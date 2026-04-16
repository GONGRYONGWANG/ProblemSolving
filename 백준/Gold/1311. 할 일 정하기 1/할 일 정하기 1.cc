#include<iostream>
using namespace std;
#define endl "\n"

/*
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	return 0;
}
*/

#include<cmath>
#include<cstring>


int cost[20][20];
int DP[20][1 << 21];
int N;

int dp(int idx, int visited) {
	if (visited == (1 << N) - 1) {
		return 0;
	}
	if (DP[idx][visited] != 0) { return DP[idx][visited]; }

	DP[idx][visited] = 200001;

	for (int i = 0; i < N; i++) {
		if (visited & (1 << i)) {
			continue;
		}
		DP[idx][visited] = min(DP[idx][visited], dp(idx + 1, visited | (1 << i))+cost[idx][i]);
	}
	return DP[idx][visited];
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> cost[i][j];
		}
	}
	memset(DP, 0, sizeof(DP));
	cout << dp(0, 0);
	return 0;
}

