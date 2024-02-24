#include<iostream>
using namespace std;
#define endl "\n"

int main() {
	int N;
	cin >> N;
	int factor = 2;
	while (N != 1) {
		if (N % factor == 0) {
			cout << factor << endl;
			N /= factor;
		}
		else{factor++;}
	}
}