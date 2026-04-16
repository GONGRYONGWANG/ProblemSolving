#include<iostream>
#include <string>
using namespace std;



int main() {
	string S;
	cin >> S;
	int tmp;
	for (int i = 97; i < 123; i++) {
		tmp = S.find((char)i);
		if (tmp > 100) { tmp = -1; }
		cout << tmp << " ";
	}
}