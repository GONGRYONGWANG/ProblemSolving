#include<iostream>
using namespace std;
#define endl "\n"

/*
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	return 0;
}*/

#include<string>


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int N;
	cin >> N;
	string S;
	cin >> S;
	for (int i = S.length() - 5; i < S.length(); i++) {
		cout << S[i];
	}

	return 0;
}