#include<iostream>
using namespace std;
#define endl "\n"

/*
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	return 0;
}
*/

int seq[50];


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> seq[i];
	}
	if (N == 1) { cout << "A"; return 0; }
	if (seq[0] == seq[1]) { 
		for (int i = 1; i < N; i++) {
			if (seq[i] != seq[0]) {
				cout << "B"; return 0;
			}
		}
		cout << seq[0]; return 0;
	}
	if (N == 2) {
		cout << "A"; return 0; 
	}
	int a = (seq[1] - seq[2]) / (seq[0] - seq[1]);
	int b = seq[1] - a * seq[0];
	for (int i = 1; i < N; i++) {
		if (seq[i] != seq[i - 1] * a + b) {
			cout << "B"; return 0;
		}
	}
	cout << a * seq[N - 1] + b;

/*
a* seq[0] +b = seq[1]
a* seq[1] +b = seq[2]
a*(seq[0]-seq[1])=seq[1]-seq[2]

*/
	

	return 0;

}