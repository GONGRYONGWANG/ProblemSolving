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
ll dist1[100001];
ll distN[100001];
ll distK[100001];

struct cmp {
    bool operator()(pll& a, pll& b) {
        return a.second > b.second;
    }
};

void solve(int tc) {

    int N, M, K; ll T;
    cin >> N >> M >> K >> T;


    while (M--) {
        int u, v, c;
        cin >> u >> v >> c;
        E[u].push_back({ v,c });
        E[v].push_back({ u,c });
    }

    {
        vector<bool> visited(N + 1, false);
        pq<pll, vector<pll>, cmp> q;
        q.push({ 1,0 });
        while (!q.empty()) {
            auto [x, d] = q.top();
            q.pop();
            if (visited[x]) continue;
            visited[x] = true;
            dist1[x] = d;
            for (auto& [nx, w] : E[x]) {
                if (visited[nx]) continue;
                q.push({ nx,d + w });
            }
        }
    }

    {
        vector<bool> visited(N + 1, false);
        pq<pll, vector<pll>, cmp> q;
        q.push({ N,0 });
        while (!q.empty()) {
            auto [x, d] = q.top();
            q.pop();
            if (visited[x]) continue;
            visited[x] = true;
            distN[x] = d;
            for (auto& [nx, w] : E[x]) {
                if (visited[nx]) continue;
                q.push({ nx,d + w });
            }
        }
    }

    {
        vector<bool> visited(N + 1, false);
        pq<pll, vector<pll>, cmp> q;
        q.push({ K,0 });
        while (!q.empty()) {
            auto [x, d] = q.top();
            q.pop();
            if (visited[x]) continue;
            visited[x] = true;
            distK[x] = d;
            for (auto& [nx, w] : E[x]) {
                if (visited[nx]) continue;
                q.push({ nx,d + w });
            }
        }
    }

    if (dist1[K] == 0 || dist1[N] == 0) {
        cout << -1;
        return;
    }

    ll ret = dist1[K] + distN[K];

    for (int i = 1; i <= N; i++) {
        if (dist1[i] == 0) continue;
        if (distK[i] > T) continue;
        ret = min(ret, dist1[i] + T + distN[i]);
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