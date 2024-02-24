#include<iostream>
using namespace std;


#include<vector>
#include<utility>
#include<string>
#include<cmath>

int main() {
	int N;
	cin >> N;
	int ans = 0;
	int stk = 0;

	while (N--) {
		char c;
		cin >> c;
		if (c == '(') {
			stk++;
		}
		else {
			stk--;
		}
		ans = max(ans, abs(stk));
	}
	if (stk != 0) {
		cout << -1;
	}
	else cout << ans;
	return 0;
}