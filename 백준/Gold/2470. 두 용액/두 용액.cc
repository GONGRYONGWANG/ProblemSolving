#include<iostream>
using namespace std;
#define endl "\n"
//ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<vector>
#include<algorithm>
#include<cmath>

int N;
int main() {
	cin >> N;
	vector<int> v;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	int p1 = 0;
	int p2 = N - 1;
	int sol = abs(v[p1] + v[p2]);
	int r1 = p1;
	int r2 = p2;
	while (p1 < p2) {
		tmp =v[p1] + v[p2];
		if (tmp == 0) {
			r1 = p1; r2 = p2;
			break;
		}
		if (abs(tmp) < sol) {
			sol = abs(tmp);
			r1 = p1; r2 = p2;
		}
		if (tmp < 0) {
			p1++;
		}
		else { p2--; }
	}
	cout << v[r1] << " " << v[r2];

	return 0;
}








