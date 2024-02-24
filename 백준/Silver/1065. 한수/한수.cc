#include<iostream>
using namespace std;

bool ishan(int i);

int main() {
	int N;
	cin >> N;

	int Num = 0;
	for (int i = 1; i <= N; i++) {
		if (ishan(i)) { Num++; }
	}
	cout << Num;
}

bool ishan(int i) {
	if (i < 100) { return 1; }

	int D1, D2, D3;
	int tmpi = i;
	D3 = tmpi % 10;
	tmpi /= 10;
	D2 = tmpi % 10;
	tmpi /= 10;
	D1 = tmpi;

	if (D1 - D2 == D2 - D3) { return 1; }
	else return 0;
}