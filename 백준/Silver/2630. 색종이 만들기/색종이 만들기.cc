#include<iostream>
#include<utility>
using namespace std;
#define endl "\n"

int N;
bool map[128][128];

pair<int, int> bw(int s1, int s2, int e1, int e2) {

	if (s1 == e1) { 
		if (map[s1][s2]) { return { 1,0 }; }
		else return { 0,1 };
	}

	pair<int,int> bw0, bw1, bw2, bw3, bw4;
	bw1 = bw(s1, s2, (s1 + e1) / 2, (s2 + e2) / 2);
	bw2 = bw((s1 + e1) / 2 + 1, s2, e1, (s2 + e2) / 2);
	bw3 = bw(s1, (s2 + e2) / 2 + 1, (s1 + e1) / 2, e2);
	bw4 = bw((s1 + e1) / 2 + 1, (s2 + e2) / 2 + 1, e1, e2);
	bw0.first = bw1.first + bw2.first + bw3.first + bw4.first;
	bw0.second = bw1.second + bw2.second + bw3.second + bw4.second;
	if (bw0.first == 0) { bw0.second = 1; }
	if (bw0.second == 0) { bw0.first = 1; }
	return bw0;
}

int main() {
	cin >> N;
	bool tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			map[i][j] = tmp;
		}
	}
	pair<int, int> BW;
	BW = bw(0, 0, N-1, N-1);
	cout << BW.second << endl<<  BW.first;
}