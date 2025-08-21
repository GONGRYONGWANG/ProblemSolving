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
const long double pi = 3.14159265358979323846;
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
ll powmod(ll x, ll n, ll mod) {
    if (n == 0) return 1;
    if (n % 2) return x * powmod(x, n - 1, mod) % mod;
    ll half = powmod(x, n / 2, mod);
    return half * half % mod;
}
ll modinv(ll x, ll mod) { // when mod is primenum
    return powmod(x, mod - 2, mod);
}
///////////////////////////////////////////////////////////////

ll N;

ll sz[5001];
int isa[5001][5001]; // isa[a][b] = true :  a is b's ancestor

vector<int> E[5001];

ll mod = 998244353;

void dfs(int x) {
    sz[x] = 1;
    isa[x][x] = 1;
    for (int nx : E[x]) {
        if (isa[nx][x]) continue;
        for (int i = 1; i <= N; i++) isa[i][nx] = isa[i][x];
        dfs(nx);
        sz[x] += sz[nx];
    }
}

void solve(int tc) {
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }


    dfs(1);
    ll base1 = modinv(N - 1, mod);
    ll base2 = modinv((N * (N - 1) / 2 - (N - 2)) % mod, mod);
    ll base = base1 * base1 % mod * base2 % mod * base2 % mod;

    ll ans = 0;
    for (int i = 2; i <= N; i++) {
        ans += sz[i] * (N - sz[i]) * sz[i] * (N - sz[i]);
        ans %= mod;
        for (int j = 2; j <= N; j++) {
            if (i == j) continue;
            ll a, b, c;
            if (isa[i][j]) {
                c = sz[j]; b = sz[i] - c; a = N - c - b;
            }
            else if (isa[j][i]) {
                a = sz[i]; b = sz[j] - a; c = N - a - b;
            }
            else {
                a = sz[i]; b = sz[j]; c = N - a - b;
            }
            ans += a * b * (a + b) * c;;
            ans += a * c * b * (a + c);
            ans %= mod;
        }
    }

    cout << ans * base % mod;

}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}