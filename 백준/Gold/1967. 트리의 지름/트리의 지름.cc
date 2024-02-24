#include<iostream>
using namespace std;
#define endl "\n"

#include<vector>
#include<utility>

#define MAX 10001

int n;

vector<pair<int, int>> E[MAX];
bool visited[MAX];


pair<int, int> FindDistance(int x) {
	visited[x] = 1;
	int distance = 0;
	int value;
	int node = x;
	pair<int, int> tmp;
	for (int i = 0; i < E[x].size(); i++) {
		if (!visited[E[x][i].first]) {
			tmp = FindDistance(E[x][i].first);
			value = tmp.second;
			value += E[x][i].second;
			if (value > distance) {
				distance = value;
				node = tmp.first;
			}
		}
	}
	return make_pair(node, distance);
}




int main() {
	cin >> n;
	int node1, node2, weight;
	for (int i = 0; i < n - 1; i++) {
		cin >> node1 >> node2 >> weight;
		E[node1].push_back(make_pair(node2, weight));
		E[node2].push_back(make_pair(node1, weight));
	}

	int FarNode = FindDistance(1).first;
	for (int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
	cout << FindDistance(FarNode).second;


	return 0;

}