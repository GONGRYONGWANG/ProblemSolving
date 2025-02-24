#include<bits/stdc++.h>
using namespace std;

void solve(int tc) {

	int X;
	cin >> X;
	X += 1;
	while (X<=9999) {
		if ((X / 100 + X % 100) * (X / 100 + X % 100) == X) {
			cout << X;
			return;
		}
		X += 1;
	}
	cout << -1;


}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T = 1;
	//cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		solve(tc);
	}
	return 0;
}