#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

#define endl "\n"
using namespace std;

int N;

int accost[1000][3];

int totalcost(vector<vector<int>> costs, int idx, int color) {
	int cost1;
	int cost2;
	if (idx == N - 1) {
		accost[idx][color] = costs[idx][color];
		return accost[N - 1][color];
	}
	if (accost[idx][color] == 0) {
		cost1 = totalcost(costs, idx + 1, (color + 1) % 3);
		cost2 = totalcost(costs, idx + 1, (color + 2) % 3);
		if (cost1 < cost2) {
			accost[idx][color] = cost1 + costs[idx][color];
			return accost[idx][color];
		}
		accost[idx][color] = cost2 + costs[idx][color];
		return accost[idx][color];
	}
	return accost[idx][color];
}

int main() {
	
	cin >> N;

	vector<vector<int>> costs(N);
	int tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> tmp;
			costs[i].push_back(tmp);
		}
	}
	
	int cost1 = totalcost(costs, 0, 0);
	int cost2 = totalcost(costs, 0, 1);
	int cost3 = totalcost(costs, 0, 2);
	if (cost1 < cost2) { cost2 = cost1; }
	if (cost2 < cost3) { cost3 = cost2; }
	cout << cost3;

	return 0;
}