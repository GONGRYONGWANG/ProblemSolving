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
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


vector<pll> E[100001];
ll H[100001];

struct cmp {
    bool operator()(pll& a, pll& b) {
        return a.second > b.second;
    }
};

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    vector<tuple<int, int, ll>> edge(M);
    for (auto& [u, v, w] : edge) {
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        E[v].push_back({ u,w });
    }

    pq<pll, vector<pll>, cmp> q;
    q.push({ 0,1 });
    while (!q.empty()) {
        auto [x, h] = q.top();
        q.pop();
        if (H[x]) continue;
        H[x] = h;
        for (auto& [nx, w] : E[x]) {
            if (H[nx]) continue;
            q.push({ nx,h + w });
        }
    }

    ll ret = 0;

    for (int x = 1; x <= N; x++) {
        ll mx = 0;
        for (auto& [nx, w] : E[x]) {
            if (H[nx] >= H[x]) continue;
            if (H[nx] + w != H[x]) continue;
            mx = max(mx, w);
        } 
        ret += mx;
    }

    cout << M - N << " " << ret;


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