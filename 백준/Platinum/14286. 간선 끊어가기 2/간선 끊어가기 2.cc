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

#define sz 501
int capacity[sz][sz];
int flow[sz][sz];
vector<int> E[sz];
int parent[sz];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        E[a].push_back(b);
        E[b].push_back(a);
        capacity[a][b] = c;
        capacity[b][a] = c;
    }
    int s, t;
    cin >> s >> t;

    int ans = 0;
    int src = s;
    int sink = t;

    while (1) {
        queue<int> q;
        q.push(src);
        fill(parent, parent + N + 1, 0);
        parent[src] = src;
        int minflow = (int)1e9;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < E[cur].size(); i++) {
                int next = E[cur][i];
                if (capacity[cur][next] - flow[cur][next] <= 0 || parent[next] != 0) continue;
                q.push(next);
                parent[next] = cur;
                if (next == sink) break;
            }
        }
        if (!parent[sink]) break;

        for (int i = sink; i != src; i = parent[i]) {
            minflow = min(minflow, capacity[parent[i]][i] - flow[parent[i]][i]);
        }

        for (int i = sink; i != src; i = parent[i]) {
            flow[parent[i]][i] += minflow;
            flow[i][parent[i]] -= minflow;
        }
        ans += minflow;

    }
    cout << ans;

    return 0;
}