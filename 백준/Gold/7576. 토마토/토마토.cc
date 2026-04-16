#include<iostream>
#include<utility>
#include<vector>
using namespace std;
#define endl "\n"

int M, N;  // 가로 세로
int Day;
vector<pair<int, int>> BFS(vector<pair<int, int>> v);
int tomatoes[1000][1000];

int main() {
	cin >> M >> N;
	Day = 0;
	int tmp;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tmp;
			tomatoes[i][j] = tmp;
			if (tmp == 1) { 
				v.push_back(make_pair(i,j));
			}
		}
	}
	BFS(v);
	cout << Day;
	return 0;
}

vector<pair<int, int>> BFS(vector<pair<int,int>> v){
	vector<pair<int, int>> result;
	pair<int, int > p , tp;
	for (int i = 0; i < v.size(); i++) {
		p = v[i];
		if (p.first != 0 && tomatoes[p.first - 1][p.second] == 0) {
			tomatoes[p.first - 1][p.second] = 1;
			result.push_back(make_pair(p.first - 1, p.second));
		}
		if (p.first != N-1 && tomatoes[p.first + 1][p.second] == 0) {
			tomatoes[p.first + 1][p.second] = 1;
			result.push_back(make_pair(p.first + 1, p.second));
		}
		if (p.second != 0 && tomatoes[p.first][p.second -1] == 0) {
			tomatoes[p.first][p.second - 1] = 1;
			result.push_back(make_pair(p.first, p.second - 1));
		}
		if (p.second != M-1 && tomatoes[p.first][p.second + 1] == 0) {
			tomatoes[p.first][p.second + 1] = 1;
			result.push_back(make_pair(p.first, p.second + 1));
		}
	}
	if (result.empty()) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (tomatoes[i][j] == 0) { Day = -1; }
			}
		}
		return result;
	}
	Day++;
	return BFS(result);
}
