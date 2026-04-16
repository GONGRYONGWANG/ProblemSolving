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
	int N;
	string S;
	cin >> N;
	cin >> S;
	if (N < 26) {
		cout << S;
		return 0;
	}

	bool state = 0;
	for (int i = 11; i < N - 12; i++) {
		if (S[i] == '.') {
			state = 1;
		}
	}

	if (!state) {
		for (int i = 0; i < 11; i++) {
			cout << S[i];
		}
		cout << "...";
		for (int i = N - 11; i < N; i++) {
			cout << S[i];
		}
		return 0;
	}

	for (int i = 0; i < 9; i++) {
		cout << S[i];
	}
	cout << "......";
	for (int i = N - 10; i < N; i++) {
		cout << S[i];
	}




	return 0;
}


