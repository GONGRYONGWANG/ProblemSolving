#include <iostream>
#include <algorithm>
#include<vector>
#include<utility>
using namespace std;

bool compare(pair<pair<int,int>, string> a, pair<pair<int,int>,string> b) {
	if (a.first.first != b.first.first) {
		return a.first.first < b.first.first;
	}
	return a.first.second < b.first.second;
}

int main() {
	int N;
	cin >> N;
	vector<pair<pair<int,int>, string>> Members(N);

	for (int i = 0; i < N; i++) {
		cin >> Members[i].first.first >> Members[i].second;
		Members[i].first.second = i;
	}
	sort(Members.begin(), Members.end(), compare);
	for (int i = 0; i < N; i++) {
		cout << Members[i].first.first << " " << Members[i].second << "\n";
	}
}