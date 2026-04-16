#include <iostream>
#include <algorithm>
#include<vector>
#include<utility>
using namespace std;

bool compare(string a, string b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	return a < b;
}

int main() {
	int N;
	cin >> N;
	vector<string> Vocas(N);
	for (int i = 0; i < N; i++) {
		cin >> Vocas[i];
	}
	sort(Vocas.begin(), Vocas.end(), compare);
	for (int i = 0; i < N; i++) {
		if (i == 0 || Vocas[i] != Vocas[i - 1]) {
			cout << Vocas[i] << "\n";
		}
	}
}