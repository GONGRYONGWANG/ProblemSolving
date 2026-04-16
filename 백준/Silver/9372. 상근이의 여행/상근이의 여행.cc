#include<iostream>
using namespace std;
#define endl "\n"
#include<vector>

int T, N, M;
bool visited[1001];

int visit(int x, vector<int> plane[1001]) {
	visited[x] = 1;
	int result = 0;

	for (int i = 0; i < plane[x].size(); i++) {
		if (!visited[plane[x][i]]) {
			result += visit(plane[x][i], plane) + 1;
		}
	}
	return result;
}

void trip() {
	vector<int> plane[1001];
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		plane[a].push_back(b);
		plane[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		visited[i] = 0;
	}
	cout << visit(1, plane)<<endl;
	return;
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		trip();
	}
	return 0;
}