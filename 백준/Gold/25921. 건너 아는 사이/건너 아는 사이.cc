#include<iostream>
using namespace std;
#define endl "\n"
typedef long long ll;
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);


#include<vector>
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int N;
	cin >> N;
	vector<bool> v(N + 1,0);
	ll ans = 0;
	for (ll i = 2; i <= N; i++) {
		if (!v[i]) {
			ans += i;
			v[i] = true;
			for (ll j = i * i; j <= N; j += i) {
				if (!v[j]) {
					ans += i;
					v[j] = true;
				}
			}
		}
	}
	cout << ans;
	return 0;
}

