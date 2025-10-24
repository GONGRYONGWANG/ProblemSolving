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
const long double pi = acosl(-1);
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()

#include<fstream>
ifstream fin; ofstream fout;

//#define cin fin 
//#define cout fout

//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


int p[200001];
int findp(int x) {
    if (p[x] == x) return x;
    return p[x] = findp(p[x]);
}

vector<pll> E[200001];
pll parent[200001][20];
int depth[200001];

ll dist(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    ll ret = 0;
    for (int j = 19; j >= 0; j--) {
        if (depth[parent[u][j].first] >= depth[v]) {
            ret += parent[u][j].second;
            u = parent[u][j].first;
        }
    }

    if (u == v) return ret;
    
    for (int j = 19; j >= 0; j--) {
        if (parent[u][j].first == parent[v][j].first) continue;
        ret += parent[u][j].second + parent[v][j].second;
        u = parent[u][j].first; v = parent[v][j].first;
    }

    return ret + parent[u][0].second + parent[v][0].second;
    
}

void solve(int tc) {

    int N;
    cin >> N;

    int a, b; ll c;

    for (int i = 1; i <= N; i++) p[i] = i;

    for (int i = 0; i < N; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (findp(u) == findp(v)) {
            a = u; b = v; c = w;
        }
        else {
            p[findp(u)] = findp(v);
            E[u].push_back({ v,w });
            E[v].push_back({ u,w });
        }
    }

    parent[1][0] = { 1,0 };
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto [nx, d] : E[x]) {
            if (parent[x][0].first == nx) continue;
            parent[nx][0] = { x,d };
            depth[nx] = depth[x] + 1;
            q.push(nx);
        }
    }

    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= N; i++) {
            parent[i][j] = parent[parent[i][j - 1].first][j - 1];
            parent[i][j].second += parent[i][j - 1].second;
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int x, y;
        cin >> x >> y;
        cout << min(dist(x, y), min(dist(x, a) + c + dist(y, b), dist(x, b) + c + dist(y, a))) << endl;
    }




    // cout << "Case #" << tc << ": " << ret<< endl;
}

int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}