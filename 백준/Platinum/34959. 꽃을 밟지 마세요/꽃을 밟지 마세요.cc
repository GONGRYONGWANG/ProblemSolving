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


ll powmod(ll x, ll n, ll mod) {
    x %= mod;
    if (n == 0) return 1;
    if (n % 2) return x * powmod(x, n - 1, mod) % mod;
    ll half = powmod(x, n / 2, mod);
    return half * half % mod;
}
ll modinv(ll x, ll mod) { // when mod is primenum
    x %= mod;
    return powmod(x, mod - 2, mod);
}



int N, M;

vector<int> E[200001];
ll F[200001];
ll Finv[200001];
int parent[200001];
int sz[200001];

void getsz(int x) {
    sz[x] = 1;
    for (int nx : E[x]) {
        if (nx == parent[x]) continue;
        parent[nx] = x;
        getsz(nx);
        sz[x] += sz[nx];
    }
}

ll ret;
ll mod = 1e9 + 7;

ll ans = 0;
void dfs(int x, ll ret) {
    ans = (ans + ret) % mod;

    for (int nx : E[x]) {
        if (nx == parent[x]) continue;
        dfs(nx, ret * F[sz[nx]] % mod * Finv[sz[nx] - 1] % mod * F[N - sz[nx] - 1] % mod * Finv[N - sz[nx]] % mod);
    }

}


void solve(int tc) {

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    if (M != N - 1) {
        cout << 0;
        return;
    }


    F[0] = 1;
    for (int i = 1; i <= N; i++) {
        F[i] = F[i - 1] * i % mod;
    }

    Finv[N] = modinv(F[N], mod);
    for (int i = N; i >= 1; i--) {
        Finv[i - 1] = Finv[i] * i % mod;
    }

    getsz(1);

    ret = F[N];
    for (int i = 1; i <= N; i++) {
        ret = ret * F[sz[i] - 1] % mod;
        ret = ret * Finv[sz[i]] % mod;
    }

    dfs(1, ret);


    cout << ans;




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