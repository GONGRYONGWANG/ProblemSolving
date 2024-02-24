#include<iostream>
#include <string>
using namespace std;



int main() {
	int N;
	cin >> N;
	
	int Moves = 1;

	N--;

	int i = 0;
	while (1) {
		N -= i * 6;
		if (N <= 0) { cout << Moves; return 0; }
		Moves++;
		i++;
	}
}