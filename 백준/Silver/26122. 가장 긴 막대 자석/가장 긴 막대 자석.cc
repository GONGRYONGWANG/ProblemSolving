#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>
#include<cmath>
int main() {
	int K;
	cin >> K;
	char x;
	int a;
	vector<int> v;
	v.push_back(0);
	while (K--) {

		cin >> x;
		if (x == 'N') {
			a = 1;
		}
		else {
			a = -1;
		}

		if (v[v.size() - 1] * a < 0) {
			v.push_back(a);
		}
		else {
			v[v.size() - 1] = v[v.size() - 1] + a;
		}
	}
	int ans = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		ans = max(ans, min(abs(v[i]), abs(v[i + 1])));
	}
	cout << 2* ans;
	return 0;
}
