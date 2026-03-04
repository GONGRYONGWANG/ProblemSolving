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

struct cmp {
    bool operator()(pll& a, pll& b) {
        return a.second > b.second;
    }
};
vector<tuple<int, ll, bool>> E[5001];

bool visited[5001];

void solve(int tc) {

    int N, M;
    cin >> N >> M;
    ll s, e;
    cin >> s >> e;
    s *= 2; e *= 2;
    while (M--) {
        int u, v;
        ll w;
        int t1, t2;
        cin >> u >> v >> w >> t1 >> t2;
        w *= 2;
        E[u].push_back({ v,w,t1 });
        E[v].push_back({ u,w,t2 });
    }

    ll ret = 0;
    pq<pll, vector<pll>, cmp> q;
    q.push({ 1,0 });
    while (!q.empty()) {
        auto [x, d] = q.top();
        q.pop();
        if (visited[x]) continue;
        visited[x] = true;
        ret = d;
        for (auto [nx, w, t] : E[x]) {
            if (visited[nx]) continue;

            if (!t || d >= e || d + w <= s) {
                q.push({ nx, d + w });
                continue;
            }

            ll nd = d;
            if (d < s) {
                w -= (s - d);
                nd = s;
            }

            ll dur = min(e - nd, w * 2);
            q.push({ nx, nd + dur + (w - dur / 2) });

        }
    }

    cout << ret / 2;
    if (ret % 2) cout << ".5";


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