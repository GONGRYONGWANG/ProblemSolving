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


int popcount(uint n) { // https://blog.naver.com/jinhan814/222540111549
    n = (n >> 1 & 0x55555555) + (n & 0x55555555);
    n = (n >> 2 & 0x33333333) + (n & 0x33333333);
    n = (n >> 4 & 0x0F0F0F0F) + (n & 0x0F0F0F0F);
    n = (n >> 8 & 0x00FF00FF) + (n & 0x00FF00FF);
    n = (n >> 16 & 0x0000FFFF) + (n & 0x0000FFFF);
    return n;
}

ll dist[14][14][14];
ll L[1001];
int K[1001];
vector<pll> E[1001];

struct cmp {
    bool operator()(pll& a, pll& b) {
        return a.second > b.second;
    }
};

ll DP[(1 << 14)][14];

void solve(int tc) {

    int N, V, M;
    cin >> N >> V >> M;

    for (int i = 1; i <= V; i++) cin >> L[i];

    for (int i = 1; i <= V; i++) {
        K[i] = -1;
    }

    for (int i = 0; i < N; i++) {
        int k; cin >> k;
        K[k] = i;
    }

    while (M--) {
        ll s, e, d;
        cin >> s >> e >> d;
        E[s].push_back({ e,d });
    }


    for (int i = 1; i <= V; i++) {
        if (K[i] == -1) continue;
        int s = K[i];
        for (int j = 1; j < N; j++) {
            for (int k = 0; k < N; k++) dist[s][j][k] = INF;

            pq<pll, vector<pll>, cmp> q;
            vector<bool> visited(V + 1, false);
            q.push({ i,0 });
            while (!q.empty()) {
                auto [x, d] = q.top();
                q.pop();
                if (visited[x]) continue;
                visited[x] = true;
                if (K[x] != -1) dist[s][j][K[x]] = d;
                for (auto& [nx, w] : E[x]) {
                    if (visited[nx]) continue;
                    if (L[nx] > j) continue;
                    q.push({ nx,w + d });
                }
            }

        }
    }

    for (int bit = 0; bit < (1 << N); bit++) {
        for (int i = 0; i < N; i++) {
            DP[bit][i] = INF;
        }
    }

    vector<bool> visited(V + 1, false);
    pq<pll, vector<pll>, cmp> q;
    q.push({ 1,0 });
    while (!q.empty()) {
        auto [x, d] = q.top();
        q.pop();
        if (visited[x]) continue;
        visited[x] = true;
        if (K[x] != -1) DP[(1 << K[x])][K[x]] = d;
        for (auto& [nx, w] : E[x]) {
            if (visited[nx]) continue;
            if (L[nx] > 0) continue;
            q.push({ nx,w + d });
        }
    }

    for (int bit = 1; bit < (1 << N); bit++) {
        for (int i = 0; i < N; i++) {
            if (bit == (1 << i)) continue;
            if (!(bit & (1 << i))) continue;
            for (int j = 0; j < N; j++) {
                if (j == i) continue;
                if (!(bit & (1 << j))) continue;
                DP[bit][i] = min(DP[bit][i], DP[bit - (1 << i)][j] + dist[j][popcount(bit) - 1][i]);
            }
        }
    }

    ll ret = INF;
    for (int i = 0; i < N; i++) {
        ret = min(ret, DP[(1 << N) - 1][i]);
    }

    if (ret == INF) cout << -1;
    else cout << ret;


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