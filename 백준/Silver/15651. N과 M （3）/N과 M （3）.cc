#include <iostream>
#include <algorithm>
#include<vector>
#include<utility>
#include<set>
using namespace std;

void Printseqs(set<int> v1, int N, int M, vector<int> v2) {
	if (M == 0) {
		for (int i = 0; i < v2.size(); i++) {
			cout << v2[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (v1.count(i) == 1) {
			v2.push_back(i);
			Printseqs(v1, N, M - 1, v2);
			v2.pop_back();
		}
	}
}

int main() {
	int N, M;
	cin >> N>> M;
	set<int> v1;
	for (int i = 1; i <= N; i++) {
		v1.insert(i);
	}
	vector<int> v2; // 사용된 숫자
	Printseqs(v1, N, M, v2);

	
}