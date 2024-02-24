#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int DP[1000000+1];


int main() {
	int N;
	cin >> N;
	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 2;
	for (int i = 3; i <= N; i++) {
		DP[i] = DP[i - 1] + DP[i - 2];
		DP[i] %= 15746;
	}
	cout << DP[N];
}