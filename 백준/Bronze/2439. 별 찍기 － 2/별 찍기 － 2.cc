#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int main() {
	cin.tie(NULL);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int k = 0; k < N - i; k++) {
			cout << " ";
		}
		for (int k = 0; k < i; k++) {
			cout << "*";
		}
		cout << "\n";
	}
}