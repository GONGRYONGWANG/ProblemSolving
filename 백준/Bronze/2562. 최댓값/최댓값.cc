#include<iostream>
using namespace std;


int main() {
	int MAX = 0;
	int MAXIDX;
	int tmp;
	for (int i = 1; i < 10; i++) {
		cin >> tmp;
		if (tmp > MAX) {
			MAX = tmp; 
			MAXIDX = i;
		}
	}
	cout << MAX << "\n" << MAXIDX;
}