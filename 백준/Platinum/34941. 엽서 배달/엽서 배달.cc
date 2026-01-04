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


ll N;
vector<pll> E[300001];
pll parent[300001];
ll sz[300001];

void dfs(int x) {
    sz[x] = 1;
    for (auto& [nx, w] : E[x]) {
        if (nx == parent[x].first) {
            parent[x].second = w;
            continue;
        }
        parent[nx].first = x;
        dfs(nx);
        sz[x] += sz[nx];
    }
}

ll get(int x, ll ret) {
    ll ans = ret;
    for (auto& [nx, w] : E[x]) {
        if (nx == parent[x].first) continue;
        ans = min(ans, get(nx, ret - w * sz[nx] + parent[nx].second * (N - sz[nx])));
    }
    return ans;
}

void solve(int tc) {

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        ll u, v, wu, wv;
        cin >> u >> v >> wu >> wv;
        E[u].push_back({ v,wu });
        E[v].push_back({ u,wv });
    }

    parent[1] = { 0,0 };
    dfs(1);

    ll ret = 0;
    for (int i = 1; i <= N; i++) {
        for (auto& [nx, w] : E[i]) {
            if (nx == parent[i].first) continue;
            ret += sz[nx] * w;
        }
    }

    cout << get(1, ret);









    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}