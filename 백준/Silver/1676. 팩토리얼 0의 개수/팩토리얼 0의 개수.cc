#include<iostream>

int main() {
	int N;
	std::cin >> N;

	int result = 0;
	while (N != 0) {
		N /= 5;
		result += N;
	}
	std::cout << result;
}