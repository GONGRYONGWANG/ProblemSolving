#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

long long stn[10][101];

long long STN(int i, int l) {
	if (i == -1 || i == 10) { return 0; }
	if (l == 1) { return 1; }
	if (stn[i][l] == 0) {
		stn[i][l] = (STN(i + 1, l - 1) + STN(i - 1, l - 1))% 1000000000;
	}
	return stn[i][l] % 1000000000;
}

int N;


int main() {
	cin >> N;
	long long total = 0;
	for (int i = 1; i < 10; i++) {
		total += STN(i, N);
	}
	cout << total% 1000000000;
}