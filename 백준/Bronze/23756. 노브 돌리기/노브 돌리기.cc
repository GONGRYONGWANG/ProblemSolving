#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int min(int a, int b) {
	if (a < b) { return a; }
	else return b;
}


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int N;
	cin >> N;
	int A;
	cin >> A;
	int ans = 0;
	int B;
	while (N--) {
		cin >> B;
		if (A > B) {
			ans += min(A - B, 360 + B - A);
		}
		else {
			ans += min(B - A, 360 + A - B);
		}
		A = B;
	}
	cout << ans;

	return 0;
}


