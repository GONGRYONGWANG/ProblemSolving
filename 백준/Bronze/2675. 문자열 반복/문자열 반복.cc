#include<iostream>
#include <string>
using namespace std;



int main() {
	int T;
	cin >> T;

	int R;
	string S;
	for (int i = 0; i < T; i++) {
		cin >> R;
		cin >> S;
		for (int k = 0; k < S.length(); k++) {
			for (int n = 0; n < R; n++) {
				cout << S[k];
			}
		}
		cout << "\n";
	}
}