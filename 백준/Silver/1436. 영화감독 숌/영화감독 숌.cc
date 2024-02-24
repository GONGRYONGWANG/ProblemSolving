#include <iostream>
using namespace std;

bool Is666(int n);


int main() {
	int N;
	cin >> N;
	int i = 0;
	while (N > 0) {
		i++;
		if (Is666(i)) { N--; }
	}
	cout << i;
}

bool Is666(int n) {
	int sixstack = 0;
	while (n > 0) {
		if (n % 10 == 6) { sixstack++; }
		else { sixstack = 0; }
		n /= 10;

		if (sixstack == 3) { return 1; }
	}
	return 0;
}