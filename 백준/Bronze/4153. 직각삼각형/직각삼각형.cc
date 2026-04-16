#include <iostream>
#include <math.h>
#include <vector>
using namespace std;


void isRAT(int a, int b, int c);

int main() {
	int a, b, c;
	while (cin >> a >> b >> c) {
		if (a == 0 && b == 0 && c == 0) { break; }
		isRAT(a, b, c);
	}
	return 0;
}



void isRAT(int a, int b, int c) {
	if (a * a + b * b == c * c) { cout << "right" << "\n"; return; }
	if (a * a + c * c == b * b) { cout << "right" << "\n"; return; }
	if (c * c + b * b == a * a) { cout << "right" << "\n"; return; }
	cout << "wrong" << "\n";
	return;
}
