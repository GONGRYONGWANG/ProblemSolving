#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int W[50], H[50];

	for (int i = 0; i < N; i++) {
		cin >> W[i] >> H[i];
	}

	int rank;
	for (int i = 0; i < N; i++) {
		rank = 1;
		for (int k = 0; k < N; k++) {
			if (W[i] < W[k] && H[i] < H[k]) {
				rank++;
			}
		}
		cout << rank << " ";
	}
}