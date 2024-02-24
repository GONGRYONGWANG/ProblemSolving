#include<iostream>
using namespace std;


int main() {
	int N;
	cin >> N;
	int Max = 0;
	int tmp;
	double total = 0;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		total += tmp;
		if (tmp > Max) { Max = tmp; }
	}

	cout << total / Max * 100 / N;


}