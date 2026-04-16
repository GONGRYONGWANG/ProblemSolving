#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define endl "\n"



vector<long long> th;
long long N, M;

long long solve();
long long solve2(long long i);
int main() {
	cin >> N >> M;

	long long tmp;
	for (long long i = 0; i < N; i++) {
		cin >> tmp;
		th.push_back(tmp);
	}
	th.push_back(0);
	sort(th.begin(), th.end());
	reverse(th.begin(), th.end()); // 내림차순 정리
	cout << solve();
	return 0;
}

long long solve() {
	for (long long i = 1; i < N + 1; i++) {
		M -= (th[i - 1] - th[i]) * i;
		if (M == 0) return th[i];
		else if (M < 0) return solve2(i);
	}
	return 0;
}

long long solve2(long long i) {
	return floor(th[i] + (-M) / i);
}