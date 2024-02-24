#include<iostream>
using namespace std;
#define endl "\n"

int main() {
	int n1, n2;
	while (1) {
		cin >> n1 >> n2;
		if (n1==0&&n2==0) {
			break;
		}
		if (n2 % n1 == 0) { cout << "factor" << endl; }
		else if (n1 % n2 == 0) { cout << "multiple" << endl; }
		else { cout << "neither"<<endl; }
	}
}