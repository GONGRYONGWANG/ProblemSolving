#include<iostream>
using namespace std;
#define endl "\n"

int DP[1001][1001];
int dp(int N, int K) {
	if (N == K) { return 1; }
	if (K > N / 2 + 1) { K = N - K; }
	if (K == 0) { return 1; }
	if (K == 1) { return N; }
	if (DP[N][K] != 0) { return DP[N][K]; }
	DP[N][K] = (dp(N - 1, K - 1) + dp(N - 1, K))%10007;
	return DP[N][K];
}

int main() {
	int N, K;
	cin >> N >> K;
	if (K > N / 2 + 1) { K = N - K; }
	cout << dp(N, K);
}