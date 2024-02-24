#include<iostream>
#include <string>
#include<cmath>
using namespace std;

int Getnum(int k, int n);


int main() {

	int T, k, n;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> k >> n;
		cout << Getnum(k, n)<<"\n";
	}
	
}

int Getnum(int k, int n) {

	if (k == 0) { return n; }

	int result=0;
	for (int i = 1; i <= n; i++) {
		result += Getnum(k - 1, i);
	}
	return result;
}
