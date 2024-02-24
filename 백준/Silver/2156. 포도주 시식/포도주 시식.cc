#include<iostream>
using namespace std;
#define endl "\n"

#define MAXSIZE 10000

int N;
int val[MAXSIZE + 3];
int DP[MAXSIZE];

int MAX(int a, int b, int c) {
	if (a > b) { b = a; }
	if (b > c) { c = b; }
	return c;
}


int dp(int idx) {
	if (idx == N - 1) { return val[N - 1]; }
	if (idx == N - 2) { return val[N - 2] + val[N - 1]; }
	if (idx >= N) { return 0; }
	if (DP[idx] != -1) { return DP[idx]; }
	DP[idx] = MAX(dp(idx + 1), val[idx] + dp(idx + 2), val[idx] + val[idx + 1] + dp(idx + 3));
	return DP[idx];
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> val[i];
		DP[i] = -1;
	}
	val[N] = 0;
	val[N + 1] = 0;
	val[N + 2] = 0;
	return;
}

void solve() {
	cout << dp(0);
	return;
}


int main() {
	input();
	solve();
	return 0;
}