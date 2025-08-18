// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cctype>
#include<vector>
#include<array>
#include<utility>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<tuple>
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
#include <immintrin.h> // AVX, AVX2, AVX-512 // #pragma GCC optimize ("O3,unroll-loops") //#pragma GCC target ("avx,avx2,fma")
#include<chrono>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
typedef long double ld;
#define pq priority_queue
#define endl "\n"
#define INF ll(2e18)
const int inf = 1000000007;
const long double pi = 3.14159265358979323846;
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

vector<pii> E[40001];
pii parent[40001][16];
int depth[40001];

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    while (M--) {
        int u, v, w;
        char d;
        cin >> u >> v >> w >> d;
        E[u].push_back({ v,w });
        E[v].push_back({ u,w });
    }

    queue<int> q;
    q.push(1);
    parent[1][0] = { 1,0 };
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (pii e: E[x]) {
            if (e.first == parent[x][0].first) continue;
            depth[e.first] = depth[x] + 1;
            parent[e.first][0].first = x;
            parent[e.first][0].second = e.second;
            q.push(e.first);
        }
    }

    for (int j = 1; j <= 15; j++) {
        for (int i = 1; i <= N; i++) {
            parent[i][j].first = parent[parent[i][j - 1].first][j - 1].first;
            parent[i][j].second = parent[i][j - 1].second + parent[parent[i][j - 1].first][j - 1].second;
        }
    }

    int K;
    cin >> K;
    while (K--) {
        int u, v;
        cin >> u >> v;
        if (depth[u] < depth[v]) swap(u, v);
        int d = depth[u] - depth[v];
        int ans = 0;
        for (int j = 0; j <= 15; j++) {
            if (d & (1 << j)) {
                ans += parent[u][j].second;
                u = parent[u][j].first;
            }
        }

        for (int j = 15; j >= 0; j--) {
            if (parent[u][j].first != parent[v][j].first) {
                ans += parent[u][j].second + parent[v][j].second;
                u = parent[u][j].first; v = parent[v][j].first;
            }
        }

        if (u != v) {
            ans += parent[u][0].second + parent[v][0].second;
        }

        cout << ans << endl;

    }






}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}