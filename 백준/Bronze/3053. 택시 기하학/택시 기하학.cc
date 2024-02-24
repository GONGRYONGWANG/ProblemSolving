#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;



int main() {
	double R;
	cin >> R;

	printf("%0.4f", R * R * M_PI);
	cout << "\n";
	printf("%0.4f", R * R * 2);
	
	return 0;
}
