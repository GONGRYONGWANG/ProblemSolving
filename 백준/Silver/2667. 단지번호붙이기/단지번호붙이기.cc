#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define endl "\n"


int N;
bool CP[25][25];

int visit(int i, int j);

int main() {
	cin >> N;
	vector<int> v;
	char  tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			if (tmp == '0') {
				CP[i][j] = 0;
			}
			else CP[i][j] = 1;
		}
	}
	int cpn=0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (CP[i][j]) {
				cpn++;
				v.push_back(visit(i, j));
			}
		}
	}
	sort(v.begin(), v.end());
	cout << cpn << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	return 0;
}

int visit(int i, int j) {
	int result = 0;
	if (!CP[i][j]) { return result; }
	result++;
	CP[i][j] = 0;
	if (i != 0) {
		result += visit(i - 1, j);
	}
	if (i != N - 1) {
		result += visit(i + 1, j);
	}
	if (j != 0) {
		result += visit(i, j - 1);
	}
	if (j != N - 1) {
		result += visit(i, j + 1);
	}
	return result;
}