#include<iostream>
#include <string>
using namespace std;



int main() {
	int N;
	cin >> N;
	string M;
	cin >> M;

	int total= 0;
	for (int i = 0; i < N; i++) {
		total += (int)M[i]-48;
	}
	cout << total;
}