#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<vector>
#include<algorithm>
int N;
int seq[1000000];
int len;
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> seq[i];
	}

	vector<int> v;


	for (int i = 0; i < N; i++) {

		int num = seq[i];
		if (v.empty()||num > v.back()) {
			v.push_back(num);
		}

		else {
			auto iter = lower_bound(v.begin(), v.end(), num);
			*iter = num;
		}
	}
	cout << v.size();
	return 0;
}