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
const ll INF = 1e18 + 7;
const int inf = 1e9 + 7;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";
#define all(x) (x).begin(), (x).end()


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

int parent[100001];
int findp(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}

set<int> sz[100001][2];
set<pii> mx[2];
bool good[100001];

void solve(int tc) {

    int N, Q;
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        int col;
        cin >> col;
        parent[i] = i;
        sz[i][col].insert(i);
        mx[col].insert({ 1,-i });
        mx[!col].insert({ 0,-i });
        good[i] = true;
    }

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;

            if (!good[findp(u)] || !good[findp(v)]) {
                u = findp(u); v = findp(v);
                if (u == v) continue;
                if (good[u]) {
                    mx[0].erase({ sz[u][0].size(),-u });
                    mx[1].erase({ sz[u][1].size(),-u });
                }
                if (good[v]) {
                    mx[0].erase({ sz[v][0].size(),-v });
                    mx[1].erase({ sz[v][1].size(),-v });
                }
                good[u] = good[v] = false;
                continue;
            }

            int ucol = 0, vcol = 0;
            if (sz[findp(u)][1].count(u)) ucol = 1;
            if (sz[findp(v)][1].count(v)) vcol = 1;

            if (findp(u) == findp(v)) {
                if (ucol != vcol) continue;
                u = findp(u);
                mx[0].erase({ sz[u][0].size(),-u });
                mx[1].erase({ sz[u][1].size(),-u });
                good[u] = false;
                continue;
            }

            u = findp(u); v = findp(v);
            if (ucol == vcol) {
                if (sz[u][0].size() + sz[u][1].size() < sz[v][0].size() + sz[v][1].size()) swap(u, v);
                mx[0].erase({ sz[v][0].size(),-v });
                mx[1].erase({ sz[v][1].size(),-v });
                swap(sz[v][0], sz[v][1]);
                mx[0].insert({ sz[v][0].size(),-v });
                mx[1].insert({ sz[v][1].size(),-v });
            }

            if (u > v) swap(u, v);
            mx[0].erase({ sz[u][0].size(),-u });
            mx[1].erase({ sz[u][1].size(),-u });
            mx[0].erase({ sz[v][0].size(),-v });
            mx[1].erase({ sz[v][1].size(),-v });
            if (sz[u][0].size() < sz[v][0].size()) swap(sz[u][0], sz[v][0]);
            if (sz[u][1].size() < sz[v][1].size()) swap(sz[u][1], sz[v][1]);

            for (int x : sz[v][0]) {
                sz[u][0].insert(x);
            }
            for (int x : sz[v][1]) {
                sz[u][1].insert(x);
            }
            parent[v] = u;
            mx[0].insert({ sz[u][0].size(),-u });
            mx[1].insert({ sz[u][1].size(),-u });
        }
        else if (t == 2) {
            int u;
            cin >> u;
            u = findp(u);
            if (!good[u]) continue;
            mx[0].erase({ sz[u][0].size(),-u });
            mx[1].erase({ sz[u][1].size(),-u });
            swap(sz[u][0], sz[u][1]);
            mx[0].insert({ sz[u][0].size(),-u });
            mx[1].insert({ sz[u][1].size(),-u });
        }
        else {
            int c;
            cin >> c;
            cout << -(mx[c].rbegin()->second) << endl;
        }
    }







}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}