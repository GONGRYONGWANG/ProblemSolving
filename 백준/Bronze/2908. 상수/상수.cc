#include<iostream>
#include <string>
using namespace std;

int reverseint(int i);
int main() {
	int A, B;
	cin >> A >> B;
	if (reverseint(A) > reverseint(B)) { cout << reverseint(A); }
	else { cout << reverseint(B); }
}

int reverseint(int i) {
	int result = 0;
	while (i != 0) {
		result *= 10;
		result += (i % 10);
		i /= 10;
	}
	return result;
}