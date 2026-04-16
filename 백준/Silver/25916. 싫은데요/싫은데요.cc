#include<iostream>
using namespace std;


#include<vector>
#include<utility>
#include<string>
#include<cmath>

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int ans = 0;
	int vol = 0;
	int f = 0;
	int b = 0;
	while (b < N) {
		vol += A[b];
		while (vol > M) {
			vol -= A[f];
			f++;
		}
		b++;
		ans = max(vol, ans);
	}
	cout << ans;
	return 0;
}