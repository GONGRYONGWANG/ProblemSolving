#include<iostream>
#include <string>
#include<cmath>
using namespace std;



int main() {
	double A, B, V;
	cin >> A >> B >> V;
	cout << (int)ceil((V - A) / (A - B)) + 1;
}