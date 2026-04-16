#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<vector>

vector<int> precon[1001];
bool isinline[1001];
vector<int> result;
bool called[1001];

bool setinline(int x) {
	if (isinline[x]) { return 1; }
	if (called[x]) { return 0; }
	called[x] = 1;
	bool b;
	for (int i = 0; i < precon[x].size(); i++) {
		b = setinline(precon[x][i]);
		if (!b) { return 0; }
	}
	isinline[x] = 1;
	result.push_back(x);
	return 1;
}

int N,M;
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N >> M;
	int k;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> k;
		if (k == 0) { continue; }
		cin >> a;
		for (int i = 0; i < k - 1; i++) {
			cin >> b;
			precon[b].push_back(a);
			a = b;
		}
	}
	bool x;
	for (int i = 1; i <= N; i++) {
		if (!isinline[i]) {
			x = setinline(i);
			if (!x) {
				cout << 0; return 0;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << result[i] << endl;
	}
	return 0;
}