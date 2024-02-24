#include<iostream>
using namespace std;


int main() {
	int A, B, C;
	cin >> A >> B >> C;

	int ABC;
	ABC = A * B * C;

	int N[10];
	for (int i = 0; i < 10; i++) {
		N[i] = 0;
	}

	while (ABC > 0) {
		N[ABC % 10]++;
		ABC /= 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << N[i] << "\n";
	}
}