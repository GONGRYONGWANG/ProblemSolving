#include<iostream>
#include <string>
#include<cmath>
using namespace std;

void Test(int H, int W, int N);

int main() {

	int T, H, W, N;
	cin >> T;


	for (int i = 0; i < T; i++) {
		cin >> H >> W >> N;
		Test(H, W, N);
	}
}

void Test(int H, int W, int N) {
	int YY, XX;

	YY = N % H;
	XX = N / H + 1;
	if (YY == 0) { 
		YY = H; 
		XX--;
	}

	printf("%d", YY);
	printf("%02d", XX);
	printf("%s", "\n");

}