#include<iostream>
using namespace std;
#define endl "\n"

/*
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	return 0;
}
*/

int seq[1000000];




int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> seq[i];
	}
	int MAXLEN = 0;
	int i = 0;
	while (i<N) {
		int min = seq[i];
		int max = seq[i];
		int minidx = i;
		int maxidx = i;
		int length = 1;
		for (int j = i+1; j < N; j++) {
			if (seq[j] >= max) { max = seq[j]; maxidx = j; }
			else if (seq[j] <= min) { min = seq[j]; minidx = j; }
			if (max - min > 2) {
				break;
			}
			length++;
		}

		if (length > MAXLEN) {
			MAXLEN = length;
		}

		if (minidx < maxidx) {
			i = minidx + 1;
		}
		else {
			i = maxidx + 1;
		}
	}
	cout << MAXLEN;
	return 0;
}