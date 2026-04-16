#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int n;

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> n;
	n %= 8;
	if (n == 1) { cout << 1; }
	else if (n == 2 || n == 8 || n==0) { cout << 2; }
	else if (n == 3 || n == 7) { cout << 3; }
	else if (n == 4 || n == 6) { cout << 4; }
	else { cout << 5; }





	return 0;
}

