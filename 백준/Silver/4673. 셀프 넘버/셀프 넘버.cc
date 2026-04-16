#include<iostream>
using namespace std;

int d(int i);

int main(){
	int N[10000];
	for (int i = 1; i < 10000; i++) {
		N[i] = 0;
	}
	int tmp;
	for (int i = 1; i < 10000; i++) {
		if (N[i] == 0) { cout << i << "\n"; }
		N[d(i)] = 1;
	}
}

int d(int i) {
	int total = 0;
	int tmpi = i;
	total += tmpi;
	for (int k = 0; k < 4; k++) {
		total += tmpi % 10;
		tmpi /= 10;
	}
	if (total >= 10000) { total = 0; }
	return total;
}