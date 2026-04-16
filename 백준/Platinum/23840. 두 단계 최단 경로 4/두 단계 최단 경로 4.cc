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

vector<pll> E[100001];
int arr[20];
ll dist[20][100001];

struct cmp {
    bool operator()(pll& a, pll& b) {
        return a.second > b.second;
    }
};

ll DP[(1 << 20)][20];

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        E[v].push_back({ u,w });
    }

    int s, t;
    cin >> s >> t;

    int P; cin >> P;

    for (int bit = 0; bit < (1 << P); bit++) {
        for (int i = 0; i < P; i++) {
            DP[bit][i] = INF;
        }
    }

    for (int i = 0; i < P; i++) {
        cin >> arr[i];
        pq<pll, vector<pll>, cmp> q;
        q.push({ arr[i],1 });
        while (!q.empty()) {
            auto [x, d] = q.top();
            q.pop();
            if (dist[i][x]) continue;
            dist[i][x] = d;
            for (auto& [nx, w] : E[x]) {
                if (dist[i][nx]) continue;
                q.push({ nx,d + w });
            }
        }
        if (dist[i][s]) DP[(1 << i)][i] = dist[i][s] - 1;
    }

    for (int bit = 1; bit < (1 << P); bit++) {
        for (int i = 0; i < P; i++) {
            if (!(bit & (1 << i))) continue;
            if (bit == (1 << i)) continue;
            for (int j = 0; j < P; j++) {
                if (j == i) continue;
                if (!(bit & (1 << j))) continue;
                if (!dist[j][arr[i]]) continue;
                DP[bit][i] = min(DP[bit][i], DP[bit - (1 << i)][j] + dist[j][arr[i]] - 1);
            }
        }
    }

    if (DP[(1 << P) - 1][0] == INF || dist[0][t] == 0) {
        cout << -1;
        return;
    }

    ll ret = INF;
    for (int i = 0; i < P; i++) {
        ret = min(ret, DP[(1 << P) - 1][i] + dist[i][t] - 1);
    }

    cout << ret;




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