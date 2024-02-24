#include<iostream>
using namespace std;
#define endl "\n"
#define INF 1e9
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);



int N;


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	int two = 0;
	int one = 0;
	int height ;
	for (int i = 0; i < N; i++) {
		cin >> height;
		two += height / 2;
		one += height % 2;
	}
	if (one > two) { cout << "NO"; return 0; }
	if ((one + 2 * two) % 3 == 0) { cout << "YES"; return 0; }
	cout << "NO";

	return 0;
}

