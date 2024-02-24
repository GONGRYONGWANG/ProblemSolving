#include<iostream>
using namespace std;
#define endl "\n"
//ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<vector>
#include<cmath>

long long min_, max_;
vector<long long> primenum;
bool isnotprime[2000001];
bool isnsn[1000001];

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);


	cin >> min_ >> max_;

	for (long long i = 2; i <= (sqrt(max_)); i++) {
		if (!isnotprime[i]) {
			for (long long j = 1; j <= (sqrt(max_)) / i; j++) {
				isnotprime[j * i] = 1;
			}
			primenum.push_back(i);
		}
	}

	for (int i = 0; i < primenum.size(); i++) {

		long long x = -(min_ % (primenum[i] * primenum[i]));
		if (x != 0) {
			x += (primenum[i] * primenum[i]);
		}
		while (x <= max_ - min_) {
			isnsn[x] = 1;
			x += primenum[i] * primenum[i];
		}
	}


	int count = 0;
	for (int i = 0; i <= max_ - min_; i++) {
		if (!isnsn[i]) {
			count++;
		}
	}
	cout << count;

	return 0;

}



