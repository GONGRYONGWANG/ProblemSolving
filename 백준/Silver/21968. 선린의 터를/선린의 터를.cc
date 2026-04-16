#include<iostream>
using namespace std;
#define endl "\n"

/*
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	return 0;
}
*/

long long find(long long n) {
	if (n == 0) {
		return 0;
	}
	long long div = 2;
	long long result = 1;
	while (div <= n) {
		div *= 2;
		result *=3;
	}
	return result += find(n -div/2);	
}



int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int T;
	cin >> T;
	long long N;
	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << find(N)<<endl;
	}
	return 0;

}