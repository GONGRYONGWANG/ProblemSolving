#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		long long N, K;
		cin >> N >> K;
		if (K >= N) {
			K = N - 1;
		}
		cout << 4 * ((K + 1) * N - K*(K + 1) / 2)<<endl;
	}
	return 0;
}

