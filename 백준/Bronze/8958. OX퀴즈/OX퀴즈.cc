#include<iostream>
#include<string>
using namespace std;


int main() {
	int N;
	cin >> N;
	string OX;
	for (int k = 0; k < N; k++) {
		cin >> OX;
		int Score = 0;
		int succession=0;
		for (int i = 0; i < OX.length(); i++) {
			if (OX[i] == 'O') {
				succession++;
				Score += succession;
			}
			else {
				succession = 0;
			}
		}
		cout << Score << "\n";
	}
}