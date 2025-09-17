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


//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

vector<tuple<ll,ll,ll>> E[50001];
ll distA[50001]; ll GA[50001];
ll distB[50001]; ll GB[50001];

struct cmp {
    bool operator()(tuple<ll, ll, ll>& A, tuple<ll, ll, ll>& B) {
        auto [x1, d1, g1] = A; auto [x2, d2, g2] = B;
        if (d1 == d2) return g1 < g2;
        return d1 > d2;
    }
};

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        E[i] = vector<tuple<ll,ll,ll>>();
        distA[i] = -1; GA[i] = -INF;
        distB[i] = -1; GB[i] = -INF;
    }

    while (M--) {
        ll u, v, t, g;
        cin >> u >> v >> t >> g;
        E[u].push_back({ v,t,g });
        E[v].push_back({ u,t,g });
    }

    pq<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, cmp> q;
    q.push({ 1,0,0 });
    while (!q.empty()) {
        auto [x, d, g] = q.top();
        q.pop();
        if (distA[x] != -1) continue;
        distA[x] = d;
        GA[x] = g;
        for (auto& [nx, t, dg] : E[x]) {
            if (distA[nx] != -1) continue;
            q.push({ nx,d + t,g + dg });
        }
    }

    q.push({ N,0,0 });
    while (!q.empty()) {
        auto [x, d, g] = q.top();
        q.pop();
        if (distB[x] != -1) continue;
        distB[x] = d;
        GB[x] = g;
        for (auto& [nx, t, dg] : E[x]) {
            if (distB[nx] != -1) continue;
            q.push({ nx,d + t,g + dg });
        }
    }


    for (int u = 1; u <= N; u++) {
        if (distA[u] == -1) continue;
        if (distA[u] + distB[u] != distA[N]) continue;

        int cnt = 0;
        for (auto& [v, t, g] : E[u]) {
            if (distA[u] + distB[v] + t == distA[N]) cnt += 1;
        }

        if (cnt >= 2) {
            cout << "Game #" << tc << ": Suckzoo ends game in time " << distA[N] << ", earning " << GA[N] << " garnet(s)." << endl;
            return;
        }
    }

    ll mnd = INF;
    ll mxg = 0;

    for (int u = 1; u <= N; u++) {
        if (distA[u] == -1) continue;
        for (auto& [v, t, g] : E[u]) {

            if (distA[u] + distB[v] + t != distA[N]) {
                if (distA[u] + distB[v] + t < mnd) {
                    mnd = distA[u] + distB[v] + t;
                    mxg = GA[u] + GB[v] + g;
                }
                else if (distA[u] + distB[v] + t == mnd) {
                    mxg = max(mxg, GA[u] + GB[v] + g);
                }
            }

            if (distA[u] + distB[v] + 3 * t < mnd) {
                mnd = distA[u] + distB[v] + 3 * t;
                mxg = GA[u] + GB[v] + 3 * g;
            }
            else if (distA[u] + distB[v] + 3 * t == mnd) {
                mxg = max(mxg, GA[u] + GB[v] + 3 * g);
            }
        }
    }

    cout << "Game #" << tc << ": Suckzoo ends game in time " << mnd << ", earning " << mxg << " garnet(s)." << endl;



}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}