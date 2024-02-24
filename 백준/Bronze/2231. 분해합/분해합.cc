#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int result=0;
	int cN;
	int i = 0;

	int tmp;
	while (i<N) {

		i++;
		cN = N - i;

		tmp = 0;
		while (cN != 0) {
			tmp += cN % 10;
			cN /= 10;
		}
		if (tmp == i) { result = N - i; }
	}
	cout << result;
}