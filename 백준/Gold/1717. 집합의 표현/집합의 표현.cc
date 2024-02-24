#include<iostream>
using namespace std;
#define endl "\n"


int parent[1000001];

int n, m;

int find_parent(int x) {
	if (parent[x] == x) { return x; }
	parent[x] = find_parent(parent[x]);
	return parent[x];
}

void merge(int a, int b) {
	if (find_parent(a) == find_parent(b)) { return; }
	parent[find_parent(a)] = find_parent(b);
	return;
}


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	int oper;
	int a; int b;

	for (int i = 0; i < m; i++) {
		cin >> oper>>a>>b;
		if (oper == 0) {  // merge
			merge(a, b);
		}
		else {   // check
			if (find_parent(a) == find_parent(b)) { cout << "YES" << endl; }
			else { cout << "NO" << endl; }
		}
	}




	return 0;
}