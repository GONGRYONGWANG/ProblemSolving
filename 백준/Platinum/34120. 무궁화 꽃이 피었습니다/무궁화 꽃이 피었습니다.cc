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

vector<pll> E[2001];
int C[2001];
ll adj[2001][2001];

struct cmp {
    bool operator()(pll& a, pll& b) {
        return a.second > b.second;
    }
};

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    while (M--) {
        ll u, v, t;
        cin >> u >> v >> t;
        E[u].push_back({ v,t });
    }
    
    for (int i = 1; i <= N; i++) cin >> C[i];

    int a, b;
    cin >> a >> b;

    for (int i = 1; i <= N; i++) {
        if (C[i]) continue;
        pq<pll, vector<pll>, cmp> q;
        vector<bool> visited(N + 1, false);
        q.push({ i,0 });

        while (!q.empty()) {
            auto [x, d] = q.top();
            q.pop();
            if (visited[x] || d > a) continue;
            visited[x] = true;
            adj[i][x] = d;
            for (pll& e : E[x]) {
                if (visited[e.first]) continue;
                q.push({ e.first, d + e.second });
            }
        }

    }
    
    pq<pll, vector<pll>, cmp> q;
    q.push({ 1,0 });
    vector<bool> visited(N + 1, false);
    while (!q.empty()) {
        auto [x, d] = q.top();
        q.pop();
        if (visited[x]) continue;
        visited[x] = true;
        if (x == N) {
            cout << d << endl;
            return;
        }
        for (int nx = 1; nx <= N; nx++) {
            if (C[nx] || !adj[x][nx]) continue;
            if (d + adj[x][nx] > d / (a + b) * (a + b) + a) q.push({ nx,d / (a + b) * (a + b) + a + b + adj[x][nx] });
            else q.push({ nx,d + adj[x][nx] });
        }
    }

    cout << -1;
    return;











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