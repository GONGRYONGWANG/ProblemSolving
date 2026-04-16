#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define endl "\n"

int N, M;
vector<vector<int>> v(101);
bool VN[101];


void DFS(int index);

int main() {
	VN[1] = 1;
	cin >> N>> M;
	int tmp1, tmp2;
	for (int i = 0; i < M; i++) {
		cin >> tmp1 >> tmp2;
		v[tmp1].push_back(tmp2);
		v[tmp2].push_back(tmp1);
	}
	DFS(1);
	int count =0;
	for (int i = 2; i <= N; i++) {
		if (VN[i]) { count++; }
	}
	cout << count;
	return 0;
}

void DFS(int index) {
	for (int i = 0; i < v[index].size(); i++) {
		if (!VN[v[index][i]]) {
			VN[v[index][i]] = 1;
			DFS(v[index][i]);
		}
	}
}