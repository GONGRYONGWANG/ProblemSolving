#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	int A;
	int B;
	int C;
	cin >> A >> B;
	C = B % 10;
	cout << A * C << endl;
	C = B % 100 - B%10;
	cout << A * C /10<< endl;
	C = B % 1000 - B%100;
	cout << A * C / 100<< endl;
	C = B;
	cout << A * C ;
}