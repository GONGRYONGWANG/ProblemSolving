// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
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
#define INF ll(4e18)
const int inf = 1e9 + 7;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;

//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
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

int parent[100001];
int findp(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}
ll sz[100001];

void solve(int tc) {


    ll N, M;
    cin >> N >> M;

    vector<vector<ll>> edges(M);
    for (int i = 0; i < M; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        edges[i] = { w,u,v };
    }

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= N; i++) parent[i] = i, sz[i] = 1;

    ll ans = 0;
    ll mod = 1e9 + 7;

    ll total = 0;

    for (vector<ll> e : edges) {
        int u = e[1]; int v = e[2];
        ll w = e[0];
        u = findp(u); v = findp(v);
        if (u == v) continue;
        total = (total + w) % mod;
        ans -= sz[u] * sz[v] % mod * ((w + 1) * w / 2 % mod) % mod;
        sz[u] += sz[v];
        parent[v] = u;
    }

    ans += total * ll(1e9 + 1) % mod * (N * (N - 1) / 2 % mod) % mod;
    ans %= mod;
    ans = (ans + mod) % mod;

    cout << ans * modinv(ll(1e9 + 1) * (N * (N - 1) / 2 % mod) % mod, mod) % mod;




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