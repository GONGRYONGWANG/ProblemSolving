#include<iostream>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;
	char a;
	int Time=0;

	for (int i = 0; i < S.length(); i++) {
		a = S[i];
		if (a == 'A' || a== 'B' ||a=='C') {
			Time += 3;
		}
		if (a == 'D' ||a=='E' || a=='F') {
			Time += 4;
		}
		if (a == 'G' || a=='H' || a=='I') {
			Time += 5;
		}
		if (a == 'J' ||a== 'K' || a=='L') {
			Time += 6;
		}
		if (a == 'M' || a=='N' || a=='O') {
			Time += 7;
		}
		if (a=='P' || a=='Q' || a=='R'||a=='S') {
			Time += 8;
		}
		if (a == 'T' ||a== 'U' || a=='V') {
			Time += 9;
		}
		if (a == 'W' || a=='X' || a=='Y'||a=='Z') {
			Time += 10;
		}
	}
	cout << Time;
}