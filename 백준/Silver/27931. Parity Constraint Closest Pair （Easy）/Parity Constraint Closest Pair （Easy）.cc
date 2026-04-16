#include<iostream>
using namespace std;
#define endl "\n"
typedef long long ll;
#define inf 1e9
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);


#include<vector>
#include<algorithm>
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	vector<int> dist(N - 1);
	for (int i = 0; i < N - 1; i++) {
		dist[i] = v[i + 1] - v[i];
	}

	int evenmin = 2e9+2;
	int oddmin = 2e9+1;
	bool wasodd = false;
	for (int i = 0; i < N - 1; i++) {
		if (dist[i] % 2 == 1) {
			oddmin = min(oddmin, dist[i]);
			if (wasodd) {
				evenmin = min(evenmin, dist[i] + dist[i - 1]);
			}
			wasodd = true;
		}
		else {
			evenmin = min(evenmin, dist[i]);
			wasodd = false;
		}
	}
	if (evenmin == 2e9 + 2) {
		evenmin = -1;
	}
	if (oddmin == 2e9 + 1) {
		oddmin = -1;
	}
	cout << evenmin << " " << oddmin;
	

	return 0;
}