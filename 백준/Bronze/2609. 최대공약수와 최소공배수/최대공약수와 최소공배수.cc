#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define endl "\n"



int main() {
	int N1, N2;
	cin >> N1 >> N2;
	int GCD;
	GCD = 1;
	int tmp = 0;
	while (tmp <= min(N1, N2)) {
		tmp += 1;
		if (N1% tmp == 0 && N2 % tmp == 0) { GCD = tmp; }
	}
	cout << GCD << endl << N1 * N2 / GCD;
}