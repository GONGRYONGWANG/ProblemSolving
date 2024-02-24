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

#define sz 2005
int capacity[sz][sz];
int flow[sz][sz];
vector<int> E[sz];
int parent[sz];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;

    int src = 2001;
    int path1 = 2002;
    int path2 = 2003;
    int sink = 2004;

    E[src].push_back(path1);
    E[path1].push_back(src);
    capacity[src][path1] = N;
    E[src].push_back(path2);
    E[path2].push_back(src);
    capacity[src][path2] = K;

    for (int i = 1; i <= N; i++) {
        E[path1].push_back(i);
        E[i].push_back(path1);
        capacity[path1][i] = 1;
        E[path2].push_back(i);
        E[i].push_back(path2);
        capacity[path2][i] = 1;
        int a;
        cin >> a;
        while (a--) {
            int x;
            cin >> x;
            x += 1000;
            E[i].push_back(x);
            E[x].push_back(i);
            capacity[i][x] = 1;
        }
    }

    for (int i = 1; i <= M; i++) {
        E[i + 1000].push_back(sink);
        E[sink].push_back(i + 1000);
        capacity[i + 1000][sink] = 1;
    }

    int ans = 0;

    while (1) {
        queue<int> q;
        q.push(src);
        fill(parent, parent + sz, 0);
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