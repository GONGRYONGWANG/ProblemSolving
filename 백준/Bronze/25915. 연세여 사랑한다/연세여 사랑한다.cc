#include<iostream>
using namespace std;


#include<vector>
#include<utility>
#include<string>
#include<cmath>

int main() {
	char c;
	cin >> c;
	string ily = "ILOVEYONSEI";
	int total = 0;
	for (int i = 0; i < ily.size(); i++) {
		total += abs(c - ily[i]);
		c = ily[i];
	}
	cout << total;



	return 0;
}