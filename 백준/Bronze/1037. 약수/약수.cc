#include<iostream>
using namespace std;
#define endl "\n"

int main() {
	int K;
	cin >> K;
	int tmp, min, max;
	cin >> tmp;
	min = tmp;
	max = tmp;
	for (int i = 1; i < K; i++) {
		cin >> tmp;
		if (tmp < min) { min = tmp; }
		if (tmp > max) { max = tmp; }
	}
	cout << min * max;
}