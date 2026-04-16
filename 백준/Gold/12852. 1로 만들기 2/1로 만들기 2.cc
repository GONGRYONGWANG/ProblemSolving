#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<vector>
#include<algorithm>
vector<int> ans;

int dp[1000001];
int Next[1000001];

void printprocess(int x) {
	cout << x<<" ";
	if (x == 1) { return; }
	printprocess(Next[x]);
	return;
}


int DP(int x) {
	if (x == 1) { return 0; }
	if (dp[x] != 0) { return dp[x]; }
	int result = 1000001;
	int tmp;
	if (x % 3 == 0) {
		tmp = DP(x / 3)+1;
		if (tmp < result) {
			result = tmp;
			Next[x] = x / 3;
		}
	}
	if (x % 2 == 0) {
		tmp = DP(x / 2)+1;
		if (tmp < result) {
			result = tmp;
			Next[x] = x / 2;
		}
	}
	tmp = DP(x - 1) + 1;
	if (tmp < result) {
		result = tmp;
		Next[x] = x - 1;
	}
	dp[x] = result;
	return dp[x];
}
int N;
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N;

	cout << DP(N)<<endl;
	printprocess(N);

	return 0;
}


