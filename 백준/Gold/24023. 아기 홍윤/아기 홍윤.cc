//#pragma warning(disable:4996) #include<bits/stdc++.h> 
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#include<iostream>
using namespace std;
#define endl "\n"
typedef long long ll;
constexpr int maxint = 1e9;
constexpr ll maxll = 1e18;

int N, K;
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> N >> K;
	int s = 1;
	int e;
	int x = 0;
	for (e = 1; e <= N; e++) {
		int tmp;
		cin >> tmp;
		x = x | tmp;
		if (x == K) { cout << s << " " << e; return 0; }
		if ((x | K) != K) { s = e + 1; x = 0; }
	}
	cout << -1;
	return 0;
}



