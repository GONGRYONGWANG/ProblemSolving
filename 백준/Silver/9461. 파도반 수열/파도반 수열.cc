#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

#define endl "\n"
using namespace std;

long long p[100] = { 1,1,1,2,2,3,4,5,7,9, };

long long P(int n) {
	if (p[n] == 0) {
		p[n] = P(n-1) + P(n-5);
	}
	return p[n];
}



int main() {
	int T;
	cin >> T;

	int N;
	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << P(N-1)<<endl;
	}
}