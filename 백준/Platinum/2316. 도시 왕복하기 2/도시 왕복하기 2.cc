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


int capacity[801][801];
int flow[801][801];
vector<int> E[801];
int parent[801];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, P;
    cin >> N >> P;
    for (int i = 1; i <= N; i++) {
        E[i * 2].push_back(i * 2 - 1);
        E[i * 2 - 1].push_back(i * 2);
        capacity[i * 2][i * 2 - 1] = 1;
    }
    capacity[2][1] = capacity[4][3] = (int)1e9;
    for (int i = 0; i < P; i++) {
        int a, b;
        cin >> a >> b;
        a *= 2;
        b *= 2;
        E[a-1].push_back(b);
        E[b].push_back(a-1);
        E[b - 1].push_back(a);
        E[a].push_back(b - 1);
        capacity[a - 1][b] = 1;
        capacity[b - 1][a] = 1;
    }

    int totalflow = 0;
    int src = 2;
    int sink = 3;

    while (1) {
        queue<int> q;
        fill(parent, parent + 2*N + 1, 0);
        q.push(src);
        parent[src] = src; 
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < E[cur].size(); i++) {
                int next = E[cur][i];
                if (capacity[cur][next] - flow[cur][next] <= 0 || parent[next]) continue;
                q.push(next);
                parent[next] = cur;
                if (next == sink) break;
            }
        }

        if (!parent[sink]) break;

        int minflow = (int)1e9;

        for (int i = sink; i != src; i = parent[i]) {
            minflow = min(minflow, capacity[parent[i]][i] - flow[parent[i]][i]);
        }

        for (int i = sink; i != src; i = parent[i]) {
            flow[parent[i]][i] += minflow;
            flow[i][parent[i]] -= minflow;
        }
        totalflow += minflow;
    }
    cout << totalflow;

    return 0;
}