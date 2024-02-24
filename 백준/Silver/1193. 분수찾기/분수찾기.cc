#include<iostream>
#include <string>
using namespace std;



int main() {
	int X;
	cin >> X;
	int i = 0;
	while (X > 0) {
		i++;
		X -= i;
	}
	if (i % 2 == 0) {
		cout << (i + X) <<"/"<< (1 - X);
	}
	else {
		cout << (1 - X) <<"/"<< (i + X);
	}
}