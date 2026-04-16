#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 1; i < 10; i++) {
		cout << N << " * " << i << " = " << N * i << endl;
	}
}