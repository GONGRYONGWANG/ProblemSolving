#include<iostream>
using namespace std;
#define endl "\n"
//ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#include<vector>

int N, M;

int parent[200];

int find(int x) {
	if (parent[x] == x) { return x; }
	parent[x] = find(parent[x]);
	return parent[x];
}

void merge(int a, int b) {
	if (find(a) == find(b)) { return; }
	parent[find(b)] = find(a);
	return;
}



int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	bool tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			if (tmp) { merge(i, j); }
		}
	}
	int departure;
	cin >> departure;
	departure--;
	int destination;
	for (int i = 0; i < M - 1; i++) {
		cin >> destination;
		destination--;
		if (find(departure) != find(destination)) { cout << "NO"; return 0; }
	}
	cout << "YES";
	return 0;
}
