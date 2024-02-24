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

const int sz = 603;
int capacity[sz][sz];
int flow[sz][sz];
int dist[sz][sz];
vector<int> E[sz];

int parent[sz];
int d[sz];
bool inq[sz];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    int N;
    cin >> N;
    vector<vector<int>> v(N+1);
    v[0] = { 0,0,0 };
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= N; j++) {
            int x;
            cin >> x;
            v[j].push_back(x);
        }
    }

    sort(v.begin(), v.end());

    int src = sz - 1;
    int sink = sz - 2;

    for (int i = 1; i <= N; i++) {
        E[src].push_back(i);
        E[i].push_back(src);
        capacity[src][i] = 1;
        E[i + N].push_back(sink);
        E[sink].push_back(i + N);
        capacity[i + N][sink] = v[i][2] - 1;
        for (int j = i + 1; j <= N; j++) {
            E[i].push_back(j + N);
            E[j + N].push_back(i);
            capacity[i][j + N] = 1;
            dist[j + N][i] = (v[i][0] ^ v[j][0]) - v[i][1] - v[j][1];
            dist[i][j + N] = -dist[j+N][i];
        }
    }
    capacity[src][N] = 0;
    capacity[N + N][sink] += 1;


    int ans = 0;

    while (1) {
        fill(d, d + sz, inf);
        fill(parent, parent + sz, 0);
        fill(inq, inq + sz, false);
        d[src] = 0;
        inq[src] = true;
        parent[src] = src;
        queue<int> q;
        q.push(src);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            inq[cur] = false;
            for (int i = 0; i < E[cur].size(); i++) {
                int next = E[cur][i];
                if (capacity[cur][next] - flow[cur][next] <= 0 || d[next] <= d[cur] + dist[cur][next]) continue;
                d[next] = d[cur] + dist[cur][next];
                parent[next] = cur;
                if (!inq[next]) {
                    q.push(next);
                    inq[next] = true;
                }
            }
        }
        if (!parent[sink]) break;
        int minflow = inf;
        for (int i = sink; i != src; i = parent[i]) {
            minflow = min(minflow, capacity[parent[i]][i] - flow[parent[i]][i]);
        }

        for (int i = sink; i != src; i = parent[i]) {
            ans -= minflow * dist[parent[i]][i];
            flow[parent[i]][i] += minflow;
            flow[i][parent[i]] -= minflow;
        }
    }
    cout << ans;
    return 0;
}