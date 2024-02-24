#include<iostream>
using namespace std;
#define endl "\n"

/*
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	return 0;
}*/


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	
	int N;
	cin >> N;
	int current, next;
	cin >> current;
	bool state = 0;
	for (int i = 1; i < N; i++) {
		cin >> next;
		if (current == next) {
			cout << "NO"; return 0;
		}
		if (!state) {
			if (next > current) {
				current = next;
			}
			else {
				current = next;
				state = 1;
			}
		}
		else {
			if (next > current) {
				cout << "NO"; return 0;
			}
			else {
				current = next;
			}
		}
	}
	cout << "YES";



	return 0;
}