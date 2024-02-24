#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int n, m;
int cnt = 0;

int parent[501];
int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = find(parent[x]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a < b) { parent[b] = a; }
	else { parent[a] = b; }
	return;
}

void sol() {
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (find(a) != find(b)) {
			merge(a, b);
		}
		else {
			merge(0, a);
		}
	}
	int result = 0;
	for (int i = 1; i <= n; i++) {
		if (find(i) == i) { result++; }
	}
	cout << "Case " << cnt << ": ";
	if (result == 0) {
		cout << "No trees.";
	}
	else if (result == 1) {
		cout << "There is one tree.";
	}
	else {
		cout << "A forest of " << result << " trees.";
	}
	cout << endl;
	return;
}




int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) {
			return 0;
		}
		cnt++;
		sol();
	}



	return 0;
}
