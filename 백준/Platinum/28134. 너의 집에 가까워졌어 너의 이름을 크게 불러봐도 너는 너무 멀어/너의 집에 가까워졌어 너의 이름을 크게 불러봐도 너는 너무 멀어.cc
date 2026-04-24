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


vector<int> E[200001];
int ind[200001];

int sz[200001];

void solve(int tc) {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
        ind[u] += 1; ind[v] += 1;
    }

    ll ans = 0;

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        sz[i] = 1;
        if (ind[i] == 1) q.push(i);
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        ans += ll(sz[x]) * ll(N - sz[x]);
        for (int nx : E[x]) {
            if (ind[nx] == 0) continue;
            sz[nx] += sz[x];
            ind[nx] -= 1; ind[x] -= 1;
            if (ind[nx] == 1) q.push(nx);
        }
    }

    int s = 0;
    for (int i = 1; i <= N; i++) {
        if (ind[i] == 0) continue;
        s = i;
        break;
    }

    ll ret = 0;
    ll psum = 0;
    vector<ll> v;
    while (1) {
        int x = s;
        v.push_back(sz[s]);
        psum += sz[s];
        ret += psum * (N - psum);
        ind[s] = 0;
        for (int nx : E[s]) {
            if (ind[nx] == 0) continue;
            s = nx;
            break;
        }
        if (s == x) break;
    }

    ll L = v.size() - 1;
    ll D = 0;
    for (int i = 0; i <= L; i++) {
        D += v[i] * i;
    }

    ll mn = ret;
    for (int x : v) {
        ret -= D * x;
        D -= (N - x);
        D += L * x;
        ret += (L * N - D) * x;
        mn = min(mn, ret);
    }


    cout << ans + mn;


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