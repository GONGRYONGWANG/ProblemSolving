#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	int Score;
	cin >> Score;
	if (Score >= 90) { cout << "A"; }
	else if (Score >= 80) { cout << "B"; }
	else if (Score >= 70) { cout << "C"; }
	else if (Score >= 60) { cout << "D"; }
	else { cout << "F"; }
}
