#include <iostream>
#include <algorithm>
#include<vector>
#include<utility>
using namespace std;



int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> Coords(N);
	for (int i = 0; i < N; i++) {
		cin >> Coords[i].first >> Coords[i].second;
	}
	sort(Coords.begin(), Coords.end());

	for (int i = 0; i < N; i++) {
		cout << Coords[i].first << " " << Coords[i].second<<"\n";
	}

}