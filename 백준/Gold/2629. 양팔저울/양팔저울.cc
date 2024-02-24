#include<iostream>
using namespace std;
#define endl "\n"

int N;
int Pd[30];
int K;
int M[7];
bool W[15001];



void input() {
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		Pd[i] = tmp;
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> tmp;
		M[i] = tmp;
	}
	return;
}
void solution() {
	W[0] = 1;
	for (int i = 1; i < 15001; i++) {
		W[i] = 0;
	}
	for (int i = 0; i < N; i++) {

		bool cW[15001];
		for (int j = 0; j < 15001; j++) {
			cW[j] = W[j];
		}

		for (int j = 0; j < 15001; j++) {
			if (cW[j]) {
				W[j + Pd[i]] = 1;
				W[abs(j - Pd[i])] = 1;
			}
		}
	}
	for (int i = 0; i < K; i++) {
		if (M[i] > 15000) { cout << "N ";}
		else if (W[M[i]]) {
			cout << "Y ";
		}
		else { cout << "N "; }
	}

	return;
}




int main() {
	input();
	solution();
	return 0;
}