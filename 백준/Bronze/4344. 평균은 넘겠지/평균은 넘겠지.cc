#include<iostream>
#include<string>
#include<iomanip>
using namespace std;


int main() {
	int C;
	cin >> C;


	for (int i = 0; i < C; i++) {

		double total = 0;
		int N;
		int M[1000];

		cin >> N;
		for (int k = 0; k < N; k++) {
			cin >> M[k];
			total += M[k];
		}
		total /= N;

		float  High = 0;
		for (int k = 0; k < N; k++) {
			if (M[k] > total) { High++; }
		}
		printf("%.3f", High / N * 100);
		cout << "%\n";
	}
}