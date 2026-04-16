#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	if (x > 0) {
		if (y > 0) { cout << "1"; }
		if (y < 0) { cout << "4"; }
	}
	else {
		if (y > 0) { cout << "2"; }
		if (y < 0) { cout << "3"; }
	}
}