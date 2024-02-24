#include<iostream>
using namespace std;
#define endl "\n"
typedef long long ll;
#define inf 1e9
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);



#include<string>
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	
	string S;
	cin >> S;
	int cnt_y = 0;
	int cnt_k = 0;
	string Y = "YONSEI";
	string K = "KOREA";
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == Y[cnt_y]) {
			cnt_y++;
		}
		if (S[i] == K[cnt_k]) {
			cnt_k++;
		}
		if (cnt_y == 6) {
			cout << Y;
			break;
		}
		if (cnt_k == 5) {
			cout << K;
			break;
		}
	}


	return 0;
}
