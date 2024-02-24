#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<cmath>
#include<vector>
#include<algorithm>


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	
	int N;
	cin >> N;
	int tmpD;
	vector<int> arr;
	for (int i = 0; i < N; i++) {
		cin >> tmpD;
		arr.push_back(int(log2(tmpD)));
	}

	sort(arr.begin(), arr.end());

	int ans = 0;
	for (int i = 0; i < (N + 1) / 2; i++) {
		ans += arr[i];
	}
	cout << ans+1;
	

	return 0;
}

