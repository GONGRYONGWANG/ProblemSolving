#include<iostream>
#include <string>
using namespace std;



int main() {
	int N;
	cin >> N;
	for (int i = N / 5; i >= 0; i--) {
		if ((N - 5 * i) % 3 == 0) {
			cout << i + (N - 5 * i) / 3;
			return 0;
		}
	}
	cout << -1;
}