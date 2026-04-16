#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int Fibonacci(int n);

int main() {
	int n;
	cin >> n;
	cout << Fibonacci(n);
}

int Fibonacci(int n) {
	if (n == 0) { return 0; }
	if (n == 1) { return 1; }
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}