#include<iostream>
using namespace std;


int main() {
	int N;
	cin >> N;
	int Max = -1000000;
	int Min = 1000000;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp > Max) { Max = tmp; }
		if (tmp < Min) { Min = tmp; }
	}
	cout << Min << " " << Max;
}