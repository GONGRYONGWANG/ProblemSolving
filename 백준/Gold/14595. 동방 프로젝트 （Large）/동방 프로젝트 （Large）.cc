#include<iostream>
using namespace std;
#define endl "\n"
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);


int r[1000001];
int l[1000001];

int N, M;
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N >> M;
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		r[x] += 1;
		l[y] += 1;
	}

	int cnt=0;
	int stack = 0;
	for (int i = 1; i <= N; i++) {
		if (l[i]!=0) {
			stack +=l[i];
		}
		if (r[i]!=0) {
			stack -= r[i];
		}
		if (stack == 0) {
			cnt++;
		}
	}
	cout << cnt;



	return 0;
}
