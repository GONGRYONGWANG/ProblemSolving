#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;



int main() {
	int N;
	cin >> N;
	int result=1;
	for (int i = 1; i <= N; i++) {
		result *= i;
	}
	cout << result;
}