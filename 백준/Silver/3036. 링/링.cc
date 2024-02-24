#include<iostream>
using namespace std;
#define endl "\n"

int min(int a, int b) {
	if (a > b) { return b; }
	return a;
}

int GCD(int a, int b) {
	for (int i = min(a, b); i > 0; i--) {
		if (a % i == 0 && b % i == 0) { return i; }
	}
}

int main() {
	int N;
	cin >> N;
	int first;
	cin >> first;
	int ring;
	int gcd;
	for (int i = 0; i < N - 1; i++) {
		cin >> ring;
		gcd = GCD(first, ring);
		cout << first / gcd << "/" << ring / gcd << endl;
	}
}