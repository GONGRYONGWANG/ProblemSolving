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

struct StoerWagner { // global mincut O(N^3)
    int N;
    vector<vector<ll>> w; // adjacency matrix

    StoerWagner(int n) : N(n), w(n + 1, vector<ll>(n + 1, 0)) {}

    void add_edge(int u, int v, ll c = 1) {
        if (u == v) return;
        w[u][v] += c;
        w[v][u] += c;
    }

    ll mincut() {
        vector<int> v(N + 1);
        iota(v.begin() + 1, v.end(), 1);
        ll best = INF;
        int n = N;

        while (n > 1) {
            vector<ll> weight(n + 1, 0);
            vector<char> added(n + 1, 0);
            int prev = -1, sel = -1;

            for (int i = 1; i <= n; i++) {
                // pick max-weight vertex not yet added
                sel = -1;
                for (int j = 1; j <= n; j++)
                    if (!added[j] && (sel == -1 || weight[j] > weight[sel]))
                        sel = j;

                added[sel] = 1;
                if (i == n) {
                    // sel is t, prev is s
                    best = min(best, weight[sel]);

                    // merge sel into prev
                    for (int j = 1; j <= n; j++) {
                        if (j == sel) continue;
                        w[v[prev]][v[j]] += w[v[sel]][v[j]];
                        w[v[j]][v[prev]] = w[v[prev]][v[j]];
                    }
                    v.erase(v.begin() + sel);
                    n--;
                    break;
                }
                prev = sel;
                for (int j = 1; j <= n; j++)
                    if (!added[j]) weight[j] += w[v[sel]][v[j]];
            }
        }
        return best;
    }
};
///////////////////////////////////////////////////////////////

int parent[501];
int findp(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) parent[i] = i;
    
    StoerWagner graph(N);

    while (M--) {
        int u, v;
        cin >> u >> v;
        parent[findp(u)] = findp(v);
        graph.add_edge(u, v);
    }

    vector<int> sz(N + 1, 0);

    bool iscon = true;
    for (int i = 1; i <= N; i++) {
        iscon &= (findp(i) == findp(1));
        sz[findp(i)] += 1;
    }

    if (iscon) {
        cout << N - 1 << endl;
        cout << N * (N - 1) / 2 - graph.mincut() + 1;
    }
    else {

        int cnt = 0;
        int mn = N;
        for (int i = 1; i <= N; i++) {
            if (sz[i]) {
                mn = min(sz[i], mn);
                cnt += 1;
            }
        }
        cout << mn * (N - mn) << endl;
        cout << N * (N - 1) / 2 - (cnt - 1) + 1;
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