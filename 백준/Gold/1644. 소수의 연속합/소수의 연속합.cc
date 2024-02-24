#include<iostream>
using namespace std;
#define endl "\n"
//ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<vector>
#include<algorithm>
#include<cmath>


int N;
vector<int> primenum;
bool isnotprime[4000001];
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N;

	for (int i = 2; i <= N; i++) {
		if (!isnotprime[i]) {
			for (int j = 1; j <= N / i; j++) {
				isnotprime[j * i] = 1;
			}
			primenum.push_back(i);
		}
	}
	primenum.push_back(0);
	int count = 0;
	int start = 0;
	int end = 0;
	int sum = 2;
	while (primenum[end] != 0) {
		if (sum == N) {
			count++;
			sum -= primenum[start];
			start++; end++;
			sum += primenum[end];
		}
		else if (sum < N) {
			end++;
			sum += primenum[end];
		}
		else {
			sum -= primenum[start];
			start++;
		}
	}
	cout << count;




	return 0;
}


