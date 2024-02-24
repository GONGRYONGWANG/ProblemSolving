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


int visited[500001][2];
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	queue<pii> q;
	q.push({ N,0 });
	while (!q.empty()) {
		int x = q.front().first;
		int t = q.front().second;
		q.pop();
		if (K + t * (t + 1) / 2 > 500000) break;
		if (x < 0 || x>500000) continue;
		if (K + t * (t + 1) / 2 == x || visited[K + t * (t + 1) / 2][t % 2]) {
			cout << t;
			return 0;
		}
		if (visited[x][t % 2]) continue;
		visited[x][t % 2] = 1;
		q.push({ x + 1,t + 1 });
		q.push({ x - 1,t + 1 });
		q.push({ x * 2,t + 1 });
	}
	cout << -1;
	return 0;
}