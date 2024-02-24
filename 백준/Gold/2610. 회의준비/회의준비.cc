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


pii ans[101];
int parent[101];
int N, M;
vector<int> E[101];
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void mer(int a, int b) {
    if (find(a) == find(b)) return;
    parent[find(a)] = find(b);
}

void bfs(int x) {
    vector<bool> visited(N + 1, 0);
    queue<pii> q;
    q.push({ x,0 });
    visited[x] = true;
    int ret = 0;
    while (!q.empty()) {
        int node = q.front().first;
        int d = q.front().second;
        q.pop();
        ret = max(ret, d);
        for (int i = 0; i < E[node].size(); i++) {
            int nxt = E[node][i];
            if (visited[nxt]) continue;
            visited[nxt] = true;
            q.push({ nxt,d + 1 });
        }
    }
    if (ret < ans[find(x)].first) {
        ans[find(x)] = { ret,x };
    }
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        ans[i] = { inf, 0};
        parent[i] = i;
    }
    while (M--) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
        mer(a, b);
    }
    for (int i = 1; i <= N; i++) {
        bfs(i);
    }
    int cnt =0;
    vector<int> rep;
    vector<bool> chk(N + 1, false);
    for (int i = 1; i <= N; i++) {
        if (chk[find(i)]) continue;
        chk[find(i)] = true;
        cnt += 1;
        rep.push_back(ans[find(i)].second);
    }
    cout << cnt << endl;
    sort(rep.begin(), rep.end());
    for (int i = 0; i < rep.size(); i++) {
        cout << rep[i] << endl;
    }
    return 0;
}