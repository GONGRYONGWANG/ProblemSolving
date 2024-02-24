#include<iostream>
using namespace std;
#define endl "\n"

/*
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	return 0;
}
*/
#include<cmath>
#include<cstring>


int cost[16][16];
int tsp[16][1 << 17];
int N;


int TSP(int x, int visited) {
	if (visited == (1 << N) - 1) {
		if (cost[x][0] == 0) { return 16000001; }
		return cost[x][0]; 
	}
	if (tsp[x][visited] != 0) {
		return tsp[x][visited];
	}

	tsp[x][visited] = 16000001;
	for (int i = 0; i < N; i++) {
		if (visited & (1 << i)) { continue; }
		if (cost[x][i] == 0) { continue; }
		tsp[x][visited] = min(tsp[x][visited], TSP(i, visited | (1 << i)) + cost[x][i]);
	}
	return tsp[x][visited];
}
	



int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> cost[i][j];
		}
	}
	memset(tsp, 0, sizeof(tsp));
	cout << TSP(0, 1<<0);
	return 0;
}
