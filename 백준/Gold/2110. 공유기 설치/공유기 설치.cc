//#pragma warning(disable:4996) #include<bits/stdc++.h> 
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#include<iostream>
using namespace std;
#define endl "\n"
typedef long long ll;
constexpr int maxint = 1e9;
constexpr ll maxll = 1e18;

int N, C;

#include<vector>
#include<algorithm>
vector<int> home;

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N >> C;
	home.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> home[i];
	}
	sort(home.begin(), home.end());
	
	int start = 1;
	int end = home[N - 1] - home[0];
	int result = 0;
	while (start <= end) {
		int mid = (start + end) / 2;
		int cnt = 1;
		int prev = home[0];
		for (int i = 1; i < N; i++) {
			if (home[i] - prev >= mid) {
				cnt += 1;
				prev = home[i];
			}
		}

		if (cnt >= C) {
			result = max(result, mid);
			start = mid + 1;
		}
		else end = mid - 1;

	}
	cout << result;
	return 0;
}
//boj #24024


