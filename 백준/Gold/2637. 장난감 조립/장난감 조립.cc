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
#include<complex> // complex number
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
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
//int dy[8] = { 1,0,-1,1,0,-1,1,-1 };
const ll INF = 1e18;
const int inf = 1e9;
const double pi = 3.14159265358979323846;

int cnt[101];
vector<pii> E[101];
int ans[101];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y, k;
        cin >> x >> y >> k;
        E[x].push_back({ y,k });
        cnt[y] += 1;
    }
    ans[N] = 1;
    queue<int> q;
    q.push(N);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (E[node].size() == 0) continue;
        for (int i = 0; i < E[node].size(); i++) {
            int nxt = E[node][i].first;
            cnt[nxt] -= 1;
            ans[nxt] += ans[node] * E[node][i].second;
            if (cnt[nxt] == 0) q.push(nxt);
        }
        ans[node] = 0;
    }
    for (int i = 1; i <= N; i++) {
        if (ans[i]) {
            cout << i << " " << ans[i] << endl;
        }
    }
    return 0;
}