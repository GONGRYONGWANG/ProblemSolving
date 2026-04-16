#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	int T;
	cin >> T;
	int A[1000];
	int a, b;
	for (int i = 0; i < T; i++) {
		cin >> a>> b;
		A[i] = a + b;
	}
	for (int i = 0; i < T; i++) {
		cout << A[i]<<endl;
	}
}