//#pragma warning(disable:4996) #include<bits/stdc++.h> 
// ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#include<iostream>
using namespace std;
#define endl "\n"
typedef long long ll;
constexpr int maxint = 1e9;
constexpr ll maxll = 1e18;

#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>


bool issqn(ll x) {
	if (sqrt(x) == (ll)sqrt(x)) { return 1; }
	else return 0;
}

ll gcd(ll a, ll b) {
	ll c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

bool ismulsqn(ll a, ll b) {
	ll g = gcd(a, b);
	a /= g;
	b /= g;
	if (issqn(a) && issqn(b)) { return 1; }
	else return 0;
}



int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int N;
	cin >> N;
	vector<ll> seq;
	vector<ll> originalseq;

	ll A;
	for (int i = 0; i < N; i++) {
		cin >> A;
		originalseq.push_back(A);
	}
	seq = originalseq;
	
	sort(seq.begin(), seq.end());
	
	for (int i = 0; i < N; i++) {
		if (!ismulsqn(seq[i],originalseq[i])) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}

