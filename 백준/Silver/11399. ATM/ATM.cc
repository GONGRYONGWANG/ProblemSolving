#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
#define endl "\n"

int N;

vector<int> T;
int main() {
	cin >> N;
	int time;
	for (int i = 0; i < N; i++) {
		cin >> time;
		T.push_back(time);
	}
	sort(T.begin(), T.end());
	int total = 0;
	for (int i = 0; i < N; i++) {
		total += T[i] * (N - i);
	}
	cout << total;
}