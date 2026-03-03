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


int dist[100001][12];
vector<pii> E[100001];

void solve(int tc) {

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 12; j++) dist[i][j] = -1;
    }

    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({ v,w });
        E[v].push_back({ u,w });
    }

    queue<pii> A, B, C;
    A.push({ 1,0 });
    while (!A.empty() || !B.empty() || !C.empty()) {
        int a, b, c;
        a = b = c = inf;
        if (!A.empty()) a = A.front().second;
        if (!B.empty()) b = B.front().second;
        if (!C.empty()) c = C.front().second;
        int mx = min(min(a, b), c);

        pii cur;
        if (mx == a) {
            cur = A.front(); A.pop();
        }
        else if (mx == b) {
            cur = B.front(); B.pop();
        }
        else {
            cur = C.front(); C.pop();
        }

        auto [x, d] = cur;
        if (dist[x][d % 12] != -1) continue;
        if (d > K) break;
        dist[x][d % 12] = d;

        for (auto& [nx, w] : E[x]) {
            int nd = d + w;
            if (dist[nx][nd % 12] != -1) continue;
            if (w == 2) A.push({ nx,nd });
            else if (w == 3) B.push({ nx,nd });
            else C.push({ nx,nd });
        }

    }

    if (dist[N][K % 12] != -1) cout << "YES";
    else cout << "NO";


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