// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
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
#include<bitset>
#include<cstdlib>
#include<ctime> // srand(time(0))
#include<regex> // 정규표현식
#include<random> // rand
#include<complex> // complex number
#include<numeric>
#include<cassert>
#include <climits>
#include<fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
#define pq priority_queue
#define endl "\n"
const ll INF = 1e18 + 7;
const int inf = 1e9 + 7;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";

//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };

/////////////////////////////////////////////////////////////////////////////////////

vector<pii> E[5001];
bool visited[5001];

struct cmp {
    bool operator()(pii& a, pii& b) {
        return a.second > b.second;
    }
    
};

void solve() {

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        E[v].push_back({ u,w });
    }
    int s, t;
    cin >> s >> t;
    pq<pii, vector<pii>, cmp> q;
    q.push({ s,0 });
    while (!q.empty()) {
        int cur = q.top().first;
        int dist = q.top().second;
        q.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        if (cur == t) {
            cout << dist;
            return;
        }
        for (pii& e : E[cur]) {
            if (visited[e.first]) continue;
            q.push({ e.first,e.second + dist });
        }
    }






}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
