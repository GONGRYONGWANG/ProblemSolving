#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int main() {
	cin.tie(NULL);

	int N;
	int X;
	int a;
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (a < X) {
			cout << a << " ";
		}
	}
}