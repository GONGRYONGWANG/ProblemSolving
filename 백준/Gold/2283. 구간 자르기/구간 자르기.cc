#pragma warning(disable:4996) 
#include<iostream>
#include <iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<utility>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<ctime> // srand(time(0))
#include<regex> // 정규표현식
#include<random> // rand
#include<complex> // complex
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
#define pq priority_queue
#define endl "\n"
#define inf 1e9
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
const double pi = 3.14159265358979323846;


int s[1000001];
int e[1000001];
int arr[1000001];
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int l, r;
		cin >> l >> r;
		s[l] += 1;
		e[r] += 1;
	}
	int line = s[0] - e[0];
	for (int i = 1; i <= 1000000; i++) {
		arr[i] = arr[i - 1] + line;
		line += s[i];
		line -= e[i];
	}
	int l = 0;
	int r = 0;
	while (r <= 1000000) {
		if (arr[r] - arr[l] == K) {
			cout << l << " " << r;
			return 0;
		}
		if (arr[r] - arr[l] < K) {
			r += 1;
		}
		else {
			l += 1;
		}
	}
	cout << "0 0";


	return 0;
}