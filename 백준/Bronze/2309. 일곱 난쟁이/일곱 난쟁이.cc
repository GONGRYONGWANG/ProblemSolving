#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

#include<vector>
#include<algorithm>
int seq[9];
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int total = -100;
	for (int i = 0; i < 9; i++) {
		cin >> seq[i];
		total += seq[i];
	}
	bool state = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (seq[i] + seq[j] == total) {
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j) {
						v.push_back(seq[k]);
					}
				}
				state = 1;
				break;
			}
		}
		if (state) { break; }
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < 7; i++) {
		cout << v[i]<<endl;
	}
	return 0;
}
