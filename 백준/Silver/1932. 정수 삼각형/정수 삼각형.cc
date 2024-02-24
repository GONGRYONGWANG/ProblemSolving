#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

#define endl "\n"
using namespace std;

long long MAXTRI[500][500];

long long MAX(long long a, long long b) {
	if (a > b) { return a; }
	return b;
}

int n;
int main() {
	cin >> n;
	vector<vector<int>> triangle(n);
	int tmp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tmp;
			triangle[i - 1].push_back(tmp);
		}
	}
	for (int i = 0; i < n; i++) {
		MAXTRI[n - 1][i] = triangle[n - 1][i];
	}
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			MAXTRI[i][j] = triangle[i][j] + MAX(MAXTRI[i + 1][j], MAXTRI[i + 1][j + 1]);
		}
	}
	cout << MAXTRI[0][0];
	
}