#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define endl "\n"

int a, b, c;
int DP[51][51][51];

int W(int a, int b, int c);
void SET();

int main() {
	while (1) {
		SET();
		if (a == -1 && b == -1 && c == -1) { return 0; }
		printf("w(%d, %d, %d) = %d \n", a, b, c, W(a,b,c));
	}
	return 0;
}

void SET() {
	cin >> a >> b >> c;
}

int W(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}
	if (DP[a][b][c] != 0) {
		return DP[a][b][c];
	}
	if (a > 20 || b > 20 || c > 20) {
		return W(20, 20, 20);
	}
	if (a < b && b < c) {
		DP[a][b][c] = W(a, b, c - 1) + W(a, b - 1, c - 1) - W(a, b - 1, c);
		return DP[a][b][c];
	}
	DP[a][b][c] = W(a - 1, b, c) + W(a - 1, b - 1, c) + W(a - 1, b, c - 1) - W(a - 1, b - 1, c - 1);
	return DP[a][b][c];
}