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

vector<pii> E[2001];

int root1[2001];
int root2[2001];
int distA[2001];
int distB[2001];
int prv[2001];

vector<int> add[2001];
vector<int> sub[2001];

struct cmp {
    bool operator()(tuple<int,int,int>& A, tuple<int,int,int>& B) {
        auto [dm1, dm2, a] = A;
        auto [dm3, dm4, b] = B;
        return a > b;
    }
};

void solve(int tc) {

    int N, M, a, b;
    cin >> N >> M >> a >> b;

    vector<tuple<int, int, int>> edges;
    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        E[v].push_back({ u,w });
        edges.push_back({ u,v,w });
    }


    int K; cin >> K;

    vector<int> arr(K);
    for (int& x : arr) cin >> x;

    distA[a] = 0;
    root1[a] = a;
    for (int i = 1; i < K; i++) {
        int u = arr[i - 1]; int v = arr[i];
        prv[v] = u;
        root1[v] = v;
        for (pii& e : E[u]) {
            if (e.first == v) {
                distA[v] = distA[u] + e.second;
            }
        }
    }

    pq<tuple<int,int,int>, vector<tuple<int,int,int>>, cmp> q;

    for (int x : arr) {
        for (auto [nx, w] : E[x]) {
            if (root1[nx]) continue;
            q.push({ nx,x,distA[x] + w });
        }
    }

    while (!q.empty()) {
        auto [x, r, d] = q.top();
        q.pop();
        if (root1[x]) continue;
        root1[x] = r;
        distA[x] = d;
        for (auto [nx, w] : E[x]) {
            if (root1[nx]) continue;
            q.push({ nx,r,distA[x] + w });
        }
    }


    distB[b] = 0;
    root2[b] = b;
    for (int i = K - 2; i >= 0; i--) {
        int u = arr[i + 1]; int v = arr[i];
        root2[v] = v;
        for (pii& e : E[v]) {
            if (e.first == u) {
                distB[v] = distB[u] + e.second;
            }
        }
    }

    for (int x : arr) {
        for (auto [nx, w] : E[x]) {
            if (root2[nx]) continue;
            q.push({ nx,x,distB[x] + w });
        }
    }

    while (!q.empty()) {
        auto [x, r, d] = q.top();
        q.pop();
        if (root2[x]) continue;
        root2[x] = r;
        distB[x] = d;
        for (auto [nx, w] : E[x]) {
            if (root2[nx]) continue;
            q.push({ nx,r,distB[x] + w });
        }
    }


    for (auto [u, v, w] : edges) {
        if (u == prv[v] || v == prv[u]) continue;
        if (distA[u] > distA[v]) swap(u, v);
        int x = root1[u]; int y = root2[v];
        if (x == y) continue;
        int ret = distA[u] + w + distB[v];
        add[x].push_back(ret); sub[y].push_back(ret);
    }

    map<int, int> m;
    m[inf] = 1;
    for (int i = 0; i < K - 1; i++) {
        int x = arr[i];
        for (int D : sub[x]) m[D] += 1;
        for (int D : add[x]) {
            m[D] -= 1;
        }
        while (m.begin()->second == 0) m.erase(m.begin());
        if (m.begin()->first == inf) cout << -1;
        else cout << m.begin()->first;
        cout << endl;
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