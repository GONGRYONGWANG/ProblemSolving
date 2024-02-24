#include<iostream>
using namespace std;
#include<vector>
#define endl "\n"
vector<int> E[100001];
int N;
int Parent[100001];
bool visited[100001];


void FindParent(int x) {
	visited[x] = 1;
	for (int i = 0; i < E[x].size(); i++) {
		if (visited[E[x][i]]) { Parent[x] = E[x][i]; }
		else FindParent(E[x][i]);
	}
	return;
}
int main() {
	cin >> N;
	int tmp1, tmp2;

	for (int i = 0; i < N - 1; i++) {
		cin >> tmp1 >> tmp2;
		E[tmp1].push_back(tmp2);
		E[tmp2].push_back(tmp1);
	}
	FindParent(1);

	for (int i = 2; i <= N; i++) {
		cout << Parent[i]<<endl;
	}

	return 0;
}

