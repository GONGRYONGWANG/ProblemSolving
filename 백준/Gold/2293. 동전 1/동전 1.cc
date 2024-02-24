#include<iostream>
using namespace std;
#include <vector>
#include<algorithm>
#define endl "\n"


int n, k;
vector<int> coin;
int DP[10001];

void input() {
	cin >> n >> k;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		coin.push_back(tmp);
	}
	return;
}
void solution() {
	DP[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			DP[j] += DP[j - coin[i]];
		}
	}
	cout << DP[k] << endl;

	return;
}



int main() {
	input();
	solution();
	return 0;
}