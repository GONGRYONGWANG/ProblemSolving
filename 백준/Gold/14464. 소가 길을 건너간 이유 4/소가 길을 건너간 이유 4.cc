#include<iostream>
#include<iomanip>
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
#include<numeric>
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

int chik[20000];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int N, M;
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        cin>> chik[i];
    }
    sort(chik, chik + M);

    pq<pii, vector<pii>, greater<pii>> cow;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        cow.push({ a,b });
    }

    pq<int, vector<int>, greater<int>> q;
    int ans = 0;
    for (int i = 0; i < M; i++) {
        int t = chik[i];
        while (!cow.empty() && cow.top().first <= t) {
            q.push(cow.top().second);
            cow.pop();
        }
        while (!q.empty() && q.top() < t) {
            q.pop();
        }
        if (!q.empty()) {
            ans += 1;
            q.pop();
        }
    }
    cout << ans;


    return 0;
}