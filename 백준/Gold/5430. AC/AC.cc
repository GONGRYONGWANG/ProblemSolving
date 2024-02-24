
#include<iostream>
using namespace std;
#define endl "\n"
#include<cstring>


int arr[100001];



void AC() {
	int n;
	string s;
	cin >> s;
	cin >> n;
	char ctmp;
	int itmp;
	int front = 0;
	int back = n;
	bool state = 0;
	for (int i = 0; i < n; i++) {
		cin >> ctmp;
		cin >> itmp;
		arr[i] = itmp;
	}
	if (n == 0) { cin >> ctmp; }
	cin >> ctmp;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'R') {
			if (state) { state = 0; }
			else state = 1;
		}
		else {
			if (!state) {
				front++;
			}
			else back--;
			if (back < front) { cout << "error" << endl; return; }
		}
	}
	cout << "[";
	if (front == back) {}
	else if (!state) {
		for (int i = front; i < back-1; i++) {
			cout << arr[i] << ",";
		}
		cout << arr[back-1];
	}
	else {
		for (int i = back-1; i > front; i--) {
			cout << arr[i] << ",";
		}
		cout << arr[front];
	}
	cout << "]";
	cout << endl;
	return;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		AC();
	}
	return 0;
}