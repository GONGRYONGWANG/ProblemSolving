#include<iostream>
using namespace std;
#include<utility>
#include<map>
#define endl "\n"

int N;

void printMAP(char** MAP) {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << MAP[i][j];
		}
		cout << endl;
	}
}

void QT(char** MAP , int n) {
	if (n == 1) { 
		cout << MAP[0][0];
		return;
	}

	bool state = 1;
	char tmp = MAP[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (MAP[i][j] != tmp) {
				state = 0;
				break;
			}
		}
		if (!state) { break; }
	}

	if (state) { 
		cout << MAP[0][0];
		return;
	}

	cout << "(";
	char** m1;
	char** m2;
	char** m3;
	char** m4;
	m1 = new char* [n / 2];
	m2 = new char* [n / 2];
	m3 = new char* [n / 2];
	m4 = new char* [n / 2];
	for (int i = 0; i < n / 2; i++) {
		m1[i] = new char[n / 2];
		m2[i] = new char[n / 2];
		m3[i] = new char[n / 2];
		m4[i] = new char[n / 2];
	}
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			m1[i][j] = MAP[i][j];
			m2[i][j] = MAP[i][j+n/2];
			m3[i][j] = MAP[i+n/2][j];
			m4[i][j] = MAP[i+n/2][j+n/2];
		}
	}

	QT(m1, n / 2);
	QT(m2, n / 2);
	QT(m3, n / 2);
	QT(m4, n / 2);

	for (int i = 0; i < n / 2; i++) {
		delete[] m1[i];
		delete[] m2[i];
		delete[] m3[i];
		delete[] m4[i];
	}
	delete[] m1;
	delete[] m2;
	delete[] m3;
	delete[] m4;


	cout << ")";
	return;
}

int main() {
	cin >> N;
	char** MAP;
	MAP = new char* [N];
	for (int i = 0; i < N; i++) {
		MAP[i] = new char[N];
	}

	char tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			MAP[i][j] = tmp;
		}
	}

	QT(MAP, N);


	for (int i = 0; i < N; i++) {
		delete[] MAP[i];
	}
	delete[] MAP;
}