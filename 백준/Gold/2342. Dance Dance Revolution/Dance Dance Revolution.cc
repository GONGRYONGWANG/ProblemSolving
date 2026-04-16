#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<vector>
#include<algorithm>
#include<cmath>
vector<int> v;

int DP[5][5][100000];

int move(int a, int b) {
	if (a == 0) {
		return 2;
	}
	if (abs(a - b) == 2) {
		return 4;
	}
	return 3;
}

int dp(int left, int right, int idx) {
	if (idx == v.size()) { return 0; }
	if (DP[left][right][idx] != 0) { return DP[left][right][idx]; }
	int x = v[idx];
	if (x == left) {
		DP[left][right][idx] = 1 + dp(left, right, idx + 1);
		return DP[right][left][idx] = DP[left][right][idx];
	}
	if (x == right) {
		DP[left][right][idx] = 1 + dp(left, right, idx + 1);
		return DP[right][left][idx] = DP[left][right][idx];
	}
	DP[left][right][idx] = min(move(left, x) + dp(x, right, idx + 1), move(right, x) + dp(left, x, idx + 1));
	return DP[right][left][idx] = DP[left][right][idx];
}



int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int tmp;
	while (1) {
		cin >> tmp;
		if (tmp == 0) { break; }
		v.push_back(tmp);
	}
	cout << dp(0, 0, 0);
	return 0;
}

