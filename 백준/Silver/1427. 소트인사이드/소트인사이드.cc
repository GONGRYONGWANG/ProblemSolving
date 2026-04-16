#include <iostream>
#include <algorithm>
#include<vector>
#include<cmath>
using namespace std;

bool compare(int a, int b);

int main() {
	int N;
	cin >> N;
	vector<int> Numbers;
	while (N != 0) {
		Numbers.push_back(N % 10);
		N /= 10;
	}
	sort(Numbers.begin(), Numbers.end(),compare);

	for (vector<int>::iterator iter = Numbers.begin(); iter != Numbers.end(); ++iter) 
	{
		cout << *iter;
	}

}

bool compare(int a, int b) {
	return a > b;
}