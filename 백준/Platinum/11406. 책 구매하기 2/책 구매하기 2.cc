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

const int sz = 203;
int capacity[sz][sz];
int flow[sz][sz];
vector<int> E[sz];

int parent[sz];


int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    int src = sz - 1;
    int sink = sz - 2;

    for (int i = 1; i <= N; i++) {
        E[i].push_back(sink);
        E[sink].push_back(i);
        cin >> capacity[i][sink];
    }
    for (int i = 101; i <= 100+M; i++) {
        E[i].push_back(src);
        E[src].push_back(i);
        cin >> capacity[src][i];
    }

    for (int i = 101; i <= 100 + M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> capacity[i][j];
            if (capacity[i][j]) {
                E[i].push_back(j);
                E[j].push_back(i);
            }
        }
    }

    int ans = 0;

    while (1) {
        queue<int> q;
        q.push(src);
        fill(parent, parent + sz, 0);
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