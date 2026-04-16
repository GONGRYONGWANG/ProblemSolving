#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int A;
	int B;
	int C;
	cin >> A >> B >> C;
	cout << (A + B) % C << endl;
	cout << ((A % C) + (B % C)) % C << endl;
	cout << (A*B) % C << endl;
	cout << ((A % C) *(B % C)) % C << endl;
}