#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define INF 1e9


	
int D, P, Q;

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> D >> P >> Q;
	if (P < Q) {
		int tmp = P;
		P = Q;
		Q = tmp;
	}
	int rt = (D / P + 1) * P;
	int ans = rt;
	int a = (D / P + 1);

	while (ans != D) {
		if (rt > D) {
			rt -= P;
			if (a == 0) { break; }
			a -= 1;
		}
		if (rt == D) {
			ans = D;
			break;
		}
		if (rt < D) {
			if ((D - rt) % Q == 0) {
				ans = D; break;
			}
			rt += ((D - rt) / Q + 1) * Q;
		}

		if (rt < ans) {
			ans = rt;
		}
		else if (rt == ans) {
			break;
		}
	}

	cout << ans;

	return 0;
}


