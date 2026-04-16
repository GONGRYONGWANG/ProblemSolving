#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

void printteam(vector<int> T);
void printstats(vector<vector<int>> stats);
int N;

int mindif = -1;

int difference(vector<vector<int>> stats, vector<int> team1) {
	bool tmp;
	vector<int> team2;
	for (int i = 0; i < N; i++) {
		tmp = 1;
		for (int j = 0; j < N / 2; j++) {
			if (i == team1[j]) {
				tmp = 0;
			}
		}
		if (tmp == 1) {
			team2.push_back(i);
		}
	}
	int total1 = 0;
	int total2 = 0;

	for (int i = 0; i < N/2; i++) {
		for (int j = 0; j < N / 2; j++) {
			total1 += stats[team1[i]][team1[j]];
			total2 += stats[team2[i]][team2[j]];
		}
	}
	int result = abs(total1 - total2);
	return result;
}

void startlink(vector<vector<int>> stats, vector<int> team1, int idx) {
	if (idx == 0) {
		int tmp = difference(stats, team1);
		if (tmp < mindif || mindif == -1) {
			mindif = tmp;
		}
		return;
	}
	for (int i = team1.back() + 1; i < N - idx + 1; i++) {
		team1.push_back(i);
		startlink(stats, team1, idx-1);
		team1.pop_back();
	}
	return;
}

int main() {
	cin >> N;
	vector<vector<int>> stats(N);
	int tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			stats[i].push_back(tmp);
		}
	}
	vector<int> team1;
	team1.push_back(0);
	startlink(stats, team1, N / 2 - 1);
	cout << mindif;
	return 0;
}