#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int Numbers[100];
	for (int i = 0; i < N; i++) {
		cin >> Numbers[i];
	}

	int total;
	int Btotal=0;
	for (int i = 0; i < N - 2; i++) {
		for (int j = i+1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				total = Numbers[i] + Numbers[j] + Numbers[k];
				if (total > M) { continue; }
				else if (total > Btotal) { Btotal = total; }
			}
			if (total > M) { continue; }
			else if (total > Btotal) { Btotal = total; }
		}
		if (total > M) { continue; }
		else if (total > Btotal) { Btotal = total; }
	}

	cout << Btotal;
}