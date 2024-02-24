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



int N;
vector<int> E[51];


int bfs(int x) {

    vector<bool> visited(N + 1, false);

    queue<pii> q;
    q.push({x,0});
    visited[x] = true;
    int ret = 0;
    while (!q.empty()) {
        int node = q.front().first;
        int d = q.front().second;
        q.pop();
        for (int i = 0; i < E[node].size(); i++) {
            int nxt = E[node][i];
            if (visited[nxt]) continue;
            visited[nxt] = true;
            q.push({ nxt, d + 1 });
        }
        ret = max(ret, d);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    while (1) {
        int a, b;
        cin >> a >> b;
        if (a == -1) break;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    int mn = inf;
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        int ret = bfs(i);
        if (ret < mn) {
            mn = ret;
            ans = { i };
        }
        else if (ret == mn) {
            ans.push_back(i);
        }
    }
    cout << mn << " " << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}