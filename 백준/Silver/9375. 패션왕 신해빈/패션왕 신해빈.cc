#include<iostream>
using namespace std;
#define endl "\n"
#include <vector>;



void Game() {
	int n;
	cin >> n;
	vector<pair<string,int>> v;
	string obj, type;
	pair<string, int> p;
	for (int i = 0; i < n; i++) {
		cin >> obj;
		cin >> type;
		if (v.empty()) {
			p.first = type;
			p.second = 1;
			v.push_back(p);
		}
		else {
			bool state = 1;
			for (int j = 0; j < v.size(); j++) {
				if (type == v[j].first) {
					v[j].second += 1;
					state = 0;
				}
			}
			if (state) {
				p.first = type;
				p.second = 1;
				v.push_back(p);
			}
		}
	}
	int total = 1;
	for (int i = 0; i < v.size(); i++) {
		total *= v[i].second + 1;
	}
	cout << total - 1<<endl;
}





int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		Game();
	}
}