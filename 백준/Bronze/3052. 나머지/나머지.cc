#include<iostream>
using namespace std;


int main() {
	int N[42];
	for (int i = 0; i < 42; i++) {
		N[i] = 0;
	}

	int Num;
	for (int i = 0; i < 10; i++) {
		cin >> Num;
		N[Num % 42] = 1;
	}

	int NofR=0;
	for (int i = 0; i < 42; i++) {
		if (N[i] == 1) { NofR++; }
	}
	cout << NofR;
}