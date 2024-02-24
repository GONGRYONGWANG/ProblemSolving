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

vector<int> E[100001];
vector<int> rE[100001];
int cnt[100001];
pll info[100001];
vector<ll> infos[100001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    while (M--) {
        int u, v;
        cin >> u >> v;
        cnt[u] += 1;
        E[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        if (E[i].size() == 0) {
            E[i].push_back(0);
            cnt[0] += 1;
        }
    }

    for (int i = 0; i <= N; i++) {
        info[i] = { INF, INF };
    }
    info[N] = { INF, 0 };

    queue<int> q;
    q.push(N);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < E[node].size(); i++) {
            int nxt = E[node][i];
            info[nxt].first = min(info[nxt].first, info[node].second);
            infos[nxt].push_back(info[node].first);
            cnt[nxt] -= 1;
            if (cnt[nxt] == 0) {
                sort(infos[nxt].rbegin(), infos[nxt].rend());
                for (int i = 0; i < infos[nxt].size(); i++) {
                    info[nxt].second = min(info[nxt].second, infos[nxt][i] + i);
                }
                q.push(nxt);
            }
        }
    }

    if (info[0].first == INF) cout << -1;
    else cout << info[0].first;


   
    return 0;
}