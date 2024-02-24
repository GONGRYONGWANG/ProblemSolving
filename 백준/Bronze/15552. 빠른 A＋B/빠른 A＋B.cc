#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int main() {
	cin.tie(NULL);

	int T;
	cin >> T;
	int a, b;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		cout << a + b << "\n";
	}
}