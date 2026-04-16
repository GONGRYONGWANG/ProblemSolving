#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;


int main() {
	int N;
	cin >> N;
	vector <int> Numbers;
	
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		Numbers.push_back(a);
	}
	sort(Numbers.begin(), Numbers.end());

	for (int i = 0; i < N; i++) {
		cout << Numbers[i]<<"\n";
	}


}