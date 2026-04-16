#include<iostream>
using namespace std;
#define endl "\n"
#include<vector>
#include<utility>

int N, M;
int MAP[12][12];
vector<pair<int,int>> island[8]; 
int isle_num = 2;
int bridge[8][8];

void assignisland(int i, int j) {
	if (MAP[i][j] == 1) {
		MAP[i][j] = isle_num;
		island[isle_num].push_back({ i,j });
		assignisland(i - 1, j);
		assignisland(i, j - 1);
		assignisland(i + 1, j);
		assignisland(i, j + 1);
	}
	return;
}

void printmap();
void printbridge();

void find_bridge(int is) {
	for (int i = 0; i < island[is].size(); i++) {
		int y = island[is][i].first;
		int x = island[is][i].second;
		for (int j = y+1; j <= N; j++) {
			if (MAP[j][x] == 0) { continue; }
			if (MAP[j][x] > is && j-y>=3) {
				if (bridge[is][MAP[j][x]] == 0 || j-y-1<bridge[is][MAP[j][x]]) {
					bridge[is][MAP[j][x]] = j - y - 1;
					bridge[MAP[j][x]][is] = j - y - 1;
				}
			}
			break;
		}
		for (int j = y - 1; j >= 0; j--) {
			if (MAP[j][x] == 0) { continue; }
			if (MAP[j][x] > is && y - j >= 3) {
				if (bridge[is][MAP[j][x]] == 0 || y - j-1 < bridge[is][MAP[j][x]]) {
					bridge[is][MAP[j][x]] = y - j - 1;
					bridge[MAP[j][x]][is] = y - j - 1;
				}
			}
			break;
		}
		for (int j = x + 1; j <= M; j++) {
			if (MAP[y][j] == 0) { continue; }
			if (MAP[y][j] > is && j - x >= 3) {
				if (bridge[is][MAP[y][j]] == 0 || j - x -1< bridge[is][MAP[y][j]]) {
					bridge[is][MAP[y][j]] = j - x-1;
					bridge[MAP[y][j]][is] = j - x - 1;
				}			
			}
			break;
		}
		for (int j = x - 1; j >= 0; j--) {
			if (MAP[y][j] == 0) { continue; }
			if (MAP[y][j] > is && x-j >= 3) {
				if (bridge[is][MAP[y][j]] == 0 || x-j-1 < bridge[is][MAP[y][j]]) {
					bridge[is][MAP[y][j]] = x-j-1;
					bridge[MAP[y][j]][is] = x - j - 1;
				}
			}
			break;
		}
	}
	return;
}


int main() {
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> MAP[i][j];
		}
	} 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (MAP[i][j] == 1) {
				assignisland(i, j);
				isle_num++;
			}
		}
	}

	isle_num--;

	for (int is = 2; is < isle_num; is++) {
		find_bridge(is);
	}
	int result = 0;
	vector<int> visitedisle;
	visitedisle.push_back(2);
	for (int i = 3; i <= isle_num; i++) {
		int minlen = 10;
		int minidx;
		for (int j = 0; j < visitedisle.size(); j++) {
			for (int k = 2; k <= isle_num; k++) {
				if (bridge[visitedisle[j]][k] != 0 && bridge[visitedisle[j]][k] < minlen) {
					minlen = bridge[visitedisle[j]][k];
					minidx = k;
				}
			}
		}
		if (minlen == 10) { cout << -1; return 0; }
		for (int j = 0; j < visitedisle.size(); j++) {
			bridge[visitedisle[j]][minidx] = 0;
			bridge[minidx][visitedisle[j]] = 0;
		}
		visitedisle.push_back(minidx);
		result += minlen;
	}
	cout << result;
	return 0;
}