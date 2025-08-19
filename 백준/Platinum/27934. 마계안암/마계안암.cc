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


vector<pll> E[100001];
vector<int> E_0[100001];
int ind[100001];

ll dist[100001];
ll DP[100001];

struct cmp {
    bool operator()(pll& a, pll& b) {
        return a.second > b.second;
    }
};

void solve(int tc) {

    int N, M;
    cin >> N >> M;
    while (M--) {
        ll u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        if (w == 0) {
            E_0[u].push_back(v);
            ind[v] += 1;
        }
    }

    queue<int> Q;
    for (int i = 1; i <= N; i++) {
        if (ind[i] == 0) Q.push(i);
    }
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        for (int nx : E_0[x]) {
            ind[nx] -= 1;
            if (ind[nx] == 0) Q.push(nx);
        }
    }

    vector<pll> v;

    pq<pll, vector<pll>, cmp> q;
    q.push({ 1,1 });
    while (!q.empty()) {
        auto [x, d] = q.top();
        q.pop();
        if (dist[x]) continue;
        dist[x] = d;
        v.push_back({ d,x });
        for (pll& e : E[x]) {
            if (dist[e.first]) continue;
            q.push({ e.first, e.second + d });
        }
    }


    sort(v.begin(), v.end());
    DP[1] = 1;
    for (int i = 1; i <= N; i++) {
        if (ind[i]) DP[i] = -1;
    }

    ll mod = 998244353;

    for (auto [d, x] : v) {
        for (pll& e : E[x]) {
            if (dist[e.first] == dist[x] + e.second) {
                if (DP[e.first] == -1 || DP[x] == -1) DP[e.first] = -1;
                else DP[e.first] = (DP[e.first] + DP[x]) % mod;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << DP[i] << endl;
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