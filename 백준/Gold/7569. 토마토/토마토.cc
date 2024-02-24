#include<iostream>
#include<utility>
#include<vector>
using namespace std;
#define endl "\n"

int M, N, H;  // 가로 세로 높이
int tomatoes[100][100][100];
int Day;

vector<vector<int>> BFS(vector<vector<int>> v);
int main() {
	cin >> M >> N >> H;
	Day = 0;
	int tmp;
	vector<vector<int>> v;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> tmp;
				tomatoes[i][j][k] = tmp;
				if (tmp == 1) {
					v.push_back({ i,j,k });
				}
			}
		}
	}
	BFS(v);
	cout << Day;
	return 0;
}

vector<vector<int>> BFS(vector<vector<int>> v) {
	vector<vector<int>> result;
	vector<int> tmp(3);
	for (int i = 0; i < v.size(); i++) {
		tmp = v[i];
		if (tmp[0] != 0 && tomatoes[tmp[0]-1][tmp[1]][tmp[2]] == 0) {
			tomatoes[tmp[0] - 1][tmp[1]][tmp[2]] = 1;
			result.push_back({ tmp[0] - 1,tmp[1],tmp[2] });
		}
		if (tmp[0] != H-1 && tomatoes[tmp[0] + 1][tmp[1]][tmp[2]] == 0) {
			tomatoes[tmp[0] + 1][tmp[1]][tmp[2]] = 1;
			result.push_back({ tmp[0] + 1,tmp[1],tmp[2] });
		}
		if (tmp[1] != 0 && tomatoes[tmp[0]][tmp[1]-1][tmp[2]] == 0) {
			tomatoes[tmp[0]][tmp[1]-1][tmp[2]] = 1;
			result.push_back({ tmp[0],tmp[1]-1,tmp[2] });
		}
		if (tmp[1] != N - 1 && tomatoes[tmp[0]][tmp[1]+1][tmp[2]] == 0) {
			tomatoes[tmp[0]][tmp[1] + 1][tmp[2]] = 1;
			result.push_back({ tmp[0],tmp[1] + 1,tmp[2] });
		}
		if (tmp[2] != 0 && tomatoes[tmp[0]][tmp[1]][tmp[2] -1] == 0) {
			tomatoes[tmp[0]][tmp[1]][tmp[2] - 1] = 1;
			result.push_back({ tmp[0],tmp[1],tmp[2] -1});
		}
		if (tmp[2] != M - 1 && tomatoes[tmp[0]][tmp[1]][tmp[2] + 1] == 0) {
			tomatoes[tmp[0]][tmp[1]][tmp[2] + 1] = 1;
			result.push_back({ tmp[0],tmp[1],tmp[2] + 1 });
		}
	}
	if (result.empty()) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) {
					if (tomatoes[i][j][k] == 0) {
						Day = -1;
					}
				}
			}
		}
		return result;
	}
	Day++;
	return BFS(result);
}
