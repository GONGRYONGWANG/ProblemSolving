#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int x2, y2;
	x2 = w - x;
	y2 = h - y;
	if (x2 <= x) { x = x2; }
	if (y2 <= y) { y = y2; }
	if (y <= x) { x = y; }
	cout << x;
}