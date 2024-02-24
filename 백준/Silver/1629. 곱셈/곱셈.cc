#include<iostream>
using namespace std;
#include<utility>
#include<vector>
#include<cmath>
#define endl "\n"

long long A, B, C;

long long DNC(long long a, long long b) {
	if (b == 0) { return 1; }
	if (b == 1) { return a % C; }
	long long nextb = floor(sqrt(b));
	long long nextb2 = b - nextb * nextb;
	return (DNC(DNC(a,nextb),nextb) * DNC(a, nextb2)) % C;
}

int main() {
	cin >> A >> B >> C;
	cout << DNC(A, B);
}