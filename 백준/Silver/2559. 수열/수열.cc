#include<iostream>
using namespace std;
#define endl "\n"
typedef long long ll;
#define inf 1e9
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);


#include<vector>
#include<utility>
#include<algorithm>




int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector<int> temp(N);
	for (int i = 0; i < N; i++) {
		cin >> temp[i];
	}
	int sum = 0;
	for (int i = 0; i < K; i++) {
		sum += temp[i];
	}
	int ans = sum;
	for (int i = K; i < N; i++) {
		sum = sum + temp[i] - temp[i - K];
		ans = max(sum, ans);
	}
	cout << ans;
	return 0;
}

