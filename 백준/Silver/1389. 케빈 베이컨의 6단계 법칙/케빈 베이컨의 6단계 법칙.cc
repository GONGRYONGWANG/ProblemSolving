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
#include<ctime> 
#include<random> // rand
#include<complex> // complex
#include<numeric>
#include<regex>
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
const double pi = 3.14159265358979323846;

vector<int> E[101];
bool visited[101];
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    int ans = 0;
    int val = (int)1e9;
    for (int i = 1; i <= N; i++) {
        int ret = 0;
        fill(visited, visited + 102, false);
        queue<pii> q;
        q.push({ i,0 });
        visited[i] = 1;
        while (!q.empty()) {
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            for (int j = 0; j < E[node].size(); j++) {
                if (!visited[E[node][j]]) {
                    visited[E[node][j]] = 1;
                    ret += dist + 1;
                    q.push({ E[node][j],dist + 1 });
                }
            }
        }
        if (ret < val) {
            ans = i;
            val = ret;
        }
    }
    cout << ans;
    return 0;
}

