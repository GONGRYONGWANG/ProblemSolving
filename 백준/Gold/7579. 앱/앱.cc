#include<iostream>
using namespace std;
#define endl "\n"

int N, M;
int m[100];
int c[100];

long long DP[10001];

long long MAX(long long a, long long b) {
	if (a < b) { return b; }
	return a;
}

void input() {
	cin >> N >> M;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		m[i] = tmp;
	}
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		c[i] = tmp;
	}
	
	return;
}
void solve() {
	for (int i = 0; i < 10001; i++) {
		DP[i] = -1;
	}
	DP[0] = 0;
	for (int j = 0; j < N; j++) {
		for (int i = 10000; i >= 0; i--) {
			if (DP[i] != -1) {
				DP[i + c[j]] = MAX(DP[i+c[j]],DP[i] + m[j]);
			}
		}
	}
	for (int i = 0; i < 10001; i++) {
		if (DP[i] >= M) {
			cout << i; return;
		}
	}

	return;
}

int main() {
	input();
	solve();
	return 0;
}