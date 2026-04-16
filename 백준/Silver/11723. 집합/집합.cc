#include<iostream>
using namespace std;
#define endl "\n"

/*
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	return 0;
}
*/
#include<string>




int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int M;
	string S;
	int D;
	int BIT = 0;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> S;
		if (S == "add") {
			cin >> D;
			BIT |= (1 << D);
		}
		else if (S == "remove") {
			cin >> D;
			BIT &= ~(1 << D);
		}
		else if (S == "check") {
			cin >> D;
			if (BIT & (1 << D)) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (S == "toggle") {
			cin >> D;
			BIT ^= (1 << D);
		}
		else if (S == "all") {
			BIT = (1 << 21) - 1;
		}
		else if (S == "empty") {
			BIT = 0;
		}
	}
	return 0;
}
