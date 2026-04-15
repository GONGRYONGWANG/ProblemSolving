#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;



int main() {
	int T;
	cin >> T;

	int x1, y1, r1, x2, y2, r2;
	for (int i = 0; i < T; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double r3 = sqrt(pow((x1 - x2),2) + pow((y1 - y2),2));
		if (r3 == 0) {
			if (r1 == r2) { cout << -1; }
			else { cout << 0; }
		}
		else if (r3 > r1+r2) { cout << 0; }
		else if (r3 == r1 + r2) { cout << 1; }
		else if (r3 == r1 - r2 || r3 == r2 - r1) { cout << 1; }
		else if (r3 < r1 - r2 || r3 < r2 - r1) { cout << 0; }
		else { cout << 2; }

		cout << "\n";
	}
}