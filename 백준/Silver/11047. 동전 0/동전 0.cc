#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
#define endl "\n"

int N, K;

int coins[10];

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> coins[i];
	}

	int total = 0;
	for (int i = N - 1; i >= 0; i--) {
		total += K / coins[i];
		K %= coins[i];
	}
	cout << total;
}