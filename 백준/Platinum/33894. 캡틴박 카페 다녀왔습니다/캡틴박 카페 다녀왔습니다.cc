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
#include<complex> // complex number
#include<numeric>
#include<cassert>
#include <climits>
#include <immintrin.h> // AVX, AVX2, AVX-512 // #pragma GCC optimize ("O3,unroll-loops") //#pragma GCC target ("avx,avx2,fma")
#include<chrono>
using namespace std;
using ll = long long;
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

#include<random> // rand
std::mt19937 gen;
void rng_init() {
    std::random_device rd;
    gen.seed(rd());  // main에서 1번
}
int randint(int l, int r) {
    std::uniform_int_distribution<int> dist(l, r);
    return dist(gen);
}

#include<fstream>
ifstream fin; ofstream fout;

//#define cin fin 
//#define cout fout

//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx8[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy8[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

vector<pll> E[200001];
int parent[200001];
ll DP[200001];

void dfs(int x) {
    for (auto& [nx, w] : E[x]) {
        if (nx == parent[x]) continue;
        parent[nx] = x;
        dfs(nx);
        DP[x] = min(DP[x], DP[nx] + w);
    }
}

ll get(int x, ll t, ll top) {

    ll mn1 = top; ll mn2 = top;

    for (auto& [nx, w] : E[x]) {
        if (nx == parent[x]) continue;
        ll d = DP[nx] + w;
        if (d < mn1) {
            mn2 = mn1; mn1 = d;
        }
        else if (d < mn2) {
            mn2 = d;
        }
    }

    ll ret = mn1;

    if (t == mn1) return t;

    for (auto& [nx, w] : E[x]) {
        if (nx == parent[x]) continue;
        ll d = DP[nx] + w;
        if (DP[nx] >= t + w) ret = max(ret, get(nx, t + w, mn1 + w));
        if (DP[nx] > mn1 + w) continue;

        if (d != mn1) ret = max(ret, (d + mn1) / 2);
        else if (mn2 != INF) ret = max(ret, (d + mn2) / 2);

    }

    return ret;

}

void solve(int tc) {

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N - 1; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        E[v].push_back({ u,w });
    }

    for (int i = 1; i <= N; i++) DP[i] = INF;

    while (K--) {
        int p; cin >> p;
        DP[p] = 0;
    }

    dfs(1);

    cout << get(1, 0, INF);


    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    rng_init();
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}