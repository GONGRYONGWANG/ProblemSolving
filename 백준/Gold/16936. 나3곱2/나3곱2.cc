#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);



#include<algorithm>

int N;
long long B[100];
int value[200];

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	long long tmp;
	int minval = 200;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		B[i] = tmp;
		int val = 100;
		while (tmp % 2 == 0) {
			tmp /= 2;
			val++;
		}
		while (tmp % 3 == 0) {
			tmp /= 3;
			val--;
		}
		value[val] = i;
		minval = min(minval, val);
	}
	for (int i = minval; i < minval + N; i++) {
		cout << B[value[i]]<<" ";
	}
	return 0;
}