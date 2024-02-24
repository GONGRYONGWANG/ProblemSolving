//#pragma warning(disable:4996) #include<bits/stdc++.h> 
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#include<iostream>
using namespace std;
#define endl "\n"
typedef long long ll;
constexpr int maxint = 1e9;
constexpr ll maxll = 1e18;


#include<string>
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	string S;
	getline(cin, S);
	int ans = 0;
	if (S.length() == 1&&S[0]==' ') {
		cout << 0;
		return 0;
	}
	for (int i = 1; i < S.length() - 1; i++) {
		if (S[i] == ' ') {
			ans++  ;
		}
	}
	ans++;
	cout << ans;
	return 0;
}

