#include<iostream>
using namespace std;
#define endl "\n"

int comb(int N, int K) {
	if (K == 0) { return 1; }
	int result = 1;

	for (int i = 0; i < K; i++) {
		result *= N - i;
	}
	for (int i = 1; i <= K; i++) {
		result /= i;
	}


	return result;
}

int main() {
	int N, K;
	cin >> N >> K;
	cout << comb(N, K);
}