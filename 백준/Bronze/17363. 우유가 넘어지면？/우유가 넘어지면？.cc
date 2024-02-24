#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int N, M;
char obj[100][100];

char rotate(char x) {
	int result = (int)x;
	if (result == 45) { return (char)124; }
	if (result == 124) { return (char)45; }
	if (result == 47) { return (char)92; }
	if (result == 92) { return (char)47; }
	if (result == 94) { return (char)60; }
	if (result == 60) { return (char)118; }
	if (result == 118) { return (char)62; }
	if (result == 62) { return (char)94; }
	return x;
}


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> obj[i][j];
		}
	}
	for (int i = M - 1; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			cout << rotate(obj[j][i]);
		}
		cout << endl;
	}

	return 0;
}

