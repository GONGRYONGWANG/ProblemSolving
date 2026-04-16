#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
#define endl "\n"

int N;

vector<pair<long long , long long >> Conf;

bool compare(pair<long long, long long> a, pair<long long, long long> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

long long time;
int assignconf(int idx) {
	time = Conf[idx].second;
	while (1) {
		if (Conf[idx].second < time) {
			time = Conf[idx].second;
		}
		idx++;
		if (idx == N) {
			return 1;
		}
		if (Conf[idx].first >= time) {
			break;
		}
	}
	return 1 + assignconf(idx);
}

int main() {
	cin >> N;
	pair<long long, long long> aconf;
	for (int i = 0; i < N; i++) {
		cin >> aconf.first >> aconf.second;
		Conf.push_back(aconf);
	}
	sort(Conf.begin(), Conf.end(), compare);
	cout << assignconf(0);
}