#include <iostream>
#include <algorithm>
#include<vector>
#include<utility>
#include<set>
using namespace std;

int MAX(int N,int Numbers[11], int Operators[4]) {
	int result = -1000000000;
	int tmp;
	if (N == 1) {
		return Numbers[0];
	}
	if (Operators[0] != 0) {
		Operators[0]--;
		result = MAX(N - 1, Numbers, Operators) + Numbers[N-1];
		Operators[0]++;
	}
	if (Operators[1] != 0) {
		Operators[1]--;
		tmp = MAX(N - 1, Numbers, Operators) - Numbers[N-1];
		if (tmp > result) { result = tmp; }
		Operators[1]++;
	}
	if (Operators[2] != 0) {
		Operators[2]--;
		tmp = MAX(N - 1, Numbers, Operators) * Numbers[N-1];
		if (tmp > result) { result = tmp; }
		Operators[2]++;
	}
	if (Operators[3] != 0) {
		Operators[3]--;
		tmp = MAX(N - 1, Numbers, Operators) / Numbers[N-1];
		if (tmp > result) { result = tmp; }
		Operators[3]++;
	}
	return result;
}
int min(int N, int Numbers[11], int Operators[4]) {
	int result = 1000000000;
	int tmp;
	if (N == 1) {
		return Numbers[0];
	}
	if (Operators[0] != 0) {
		Operators[0]--;
		result = min(N - 1, Numbers, Operators) + Numbers[N - 1];
		Operators[0]++;
	}
	if (Operators[1] != 0) {
		Operators[1]--;
		tmp = min(N - 1, Numbers, Operators) - Numbers[N - 1];
		if (tmp < result) { result = tmp; }
		Operators[1]++;
	}
	if (Operators[2] != 0) {
		Operators[2]--;
		tmp = min(N - 1, Numbers, Operators) * Numbers[N - 1];
		if (tmp < result) { result = tmp; }
		Operators[2]++;
	}
	if (Operators[3] != 0) {
		Operators[3]--;
		tmp = min(N - 1, Numbers, Operators) / Numbers[N - 1];
		if (tmp < result) { result = tmp; }
		Operators[3]++;
	}
	return result;
}
int main() {
	int Numbers[11];
	int Operators[4];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Numbers[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> Operators[i];
	}
	cout << MAX(N, Numbers, Operators) << "\n";
	cout << min(N, Numbers, Operators);
}
