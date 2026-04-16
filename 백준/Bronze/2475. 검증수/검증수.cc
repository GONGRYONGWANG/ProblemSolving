#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);




int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int result = 0;
	int tmp;
	for (int i = 0; i < 5; i++) {
		cin >> tmp;
		result += tmp * tmp;
	}
	cout << result % 10;
	return 0;
}
