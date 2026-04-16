#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);



int parent[300001];

int find(int x) {
	if (parent[x] == x) { return x; }
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	if (find(a) == find(b)) { return; }
	a = find(a);
	b = find(b);
	if (a < b) { parent[b] = a; }
	else parent[a] = b;
	return;
}






int N, L;

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	
	cin >> N >> L;

	for (int i = 0; i <= L; i++) {
		parent[i] = i;
	}

	int A, B;
	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		if (find(A) == 0 && find(B) == 0) {
			cout << "SMECE"<<endl;
			continue;
		}
		else if (find(A) != find(B)) {
			merge(A, B);
		}
		else {
			merge(A, 0);
		}
		cout << "LADICA"<<endl;
	}


	return 0;
}
