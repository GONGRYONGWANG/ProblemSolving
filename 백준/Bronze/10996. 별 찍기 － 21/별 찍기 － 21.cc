#include<iostream>
using namespace std;

void printstar(int N);


int main() {
	int N ;
	cin >> N;
	for (int i = 0; i < N; i++) {
		printstar(N);
	}
}

void printstar(int N) {
	if (N == 1) { 
		cout << "*"; 
		return;
	}
	for (int i = 0; i < (N / 2 + N % 2); i++) {
		cout << "* ";
	}
	cout << "\n";
	for (int i = 0; i < (N / 2); i++) {
		cout << " *";
	}
	cout << "\n";
}