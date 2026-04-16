#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<vector>
#include<algorithm>
int N;
vector<int> cost[1000];
int DP[3][3][1000];

int dp(int scolor, int ccolor, int idx) {
	if (idx == N - 1) {
		int result = 1001;
		if (scolor != 0 && ccolor != 0) {
			result = min(result, cost[idx][0]);
		}
		if (scolor != 1 && ccolor != 1) {
			result = min(result, cost[idx][1]);
		}
		if (scolor != 2 && ccolor != 2) {
			result = min(result, cost[idx][2]);
		}
		return result;
	}
	if (DP[scolor][ccolor][idx] != 0) { return DP[scolor][ccolor][idx]; }
	if (ccolor == 0) {
		return DP[scolor][ccolor][idx] = min(dp(scolor, 1, idx + 1) + cost[idx][1], dp(scolor, 2, idx + 1) + cost[idx][2]);
	}
	if (ccolor == 1) {
		return DP[scolor][ccolor][idx] = min(dp(scolor, 2, idx + 1) + cost[idx][2], dp(scolor, 0, idx + 1) + cost[idx][0]);
	}
	if (ccolor == 2) {
		return DP[scolor][ccolor][idx] = min(dp(scolor, 0, idx + 1) + cost[idx][0], dp(scolor, 1, idx + 1) + cost[idx][1]);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	int r, g, b;
	for (int i = 0; i < N; i++) {
		cin >> r >> g >> b;
		cost[i] = { r,g,b };
	}
	int result = min(dp(0, 0, 1) + cost[0][0] , dp(1, 1, 1)+cost[0][1]);
	result = min(result, dp(2, 2, 1) + cost[0][2]);
	cout << result;
	return 0;
}