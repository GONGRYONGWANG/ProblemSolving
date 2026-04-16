#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

long long Fibo[100] = { 0,1, };

long long Fibonacci(int N) {
	if (N == 0 || N==1) {
		return Fibo[N];
	}
	else if (Fibo[N] == 0) {
		Fibo[N] = Fibonacci(N - 1) + Fibonacci(N - 2);
	}
	return Fibo[N];
}

int main() {
	int N;
	cin >> N;
	cout << Fibonacci(N);
}