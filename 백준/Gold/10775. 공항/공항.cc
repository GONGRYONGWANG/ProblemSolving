#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);






int G, P;
int parent[100001];

int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	else {
		return parent[x] = find(parent[x]);
	}
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	parent[a] = b;
}


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> G >> P;

	int cnt = 0;
	for (int i = 0; i <= G; i++) {
		parent[i] = i;
	}
	int g;
	for (int i = 0; i < P; i++) {
		cin >> g;
		int gate = find(g);
		if (gate == 0) {
			break;
		}
		else {
			cnt++;
			merge(gate, gate - 1);
		}
	}
	cout << cnt;
	
	return 0;

}
