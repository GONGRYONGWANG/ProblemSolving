#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<map>
#include<string>

int parent[200000];
int child[200000];

int find(int x) {
	if (parent[x] == x) { return x; }
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	if (find(a) == find(b)) { return; }
	a = find(a);
	b = find(b);
	parent[b] = a;
	child[a] += child[b];
	return;
}


void TEST() {
	map<string, int> assign;
	int N;
	cin >> N;

	for (int i = 0; i < 2 * N; i++) {
		parent[i] = i;
		child[i] = 1;
	}

	string a, b;
	int idx = 0;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		if (assign.find(a) == assign.end()) {
			assign.insert({ a,idx });
			idx++;
		}
		if (assign.find(b) == assign.end()) {
			assign.insert({ b,idx });
			idx++;
		}
		int x = assign[a];
		int y = assign[b];
		merge(x, y);
		cout << child[find(x)]<<endl;
	}
	return;
}




int T;
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	
	cin >> T;
	for (int i = 0; i < T; i++) {
		TEST();
	}

	return 0;
}