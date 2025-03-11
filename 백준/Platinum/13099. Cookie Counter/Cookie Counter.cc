// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
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
const ll INF = 1e18 + 7;
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

ll N, D, X;
ll DP[2001][2001];
ll Psum[2001][2001];
ll mod = 1e9 + 7;

ll psum(int n, int x);

ll dp(int n, int x) {
    if (x == 0) return 1;
    if (n == 0) return 0;
    if (DP[n][x] != -1) return DP[n][x];
    return DP[n][x] = (psum(n - 1, x) - psum(n - 1, max(0ll, x - (X - 2)) - 1) + mod) % mod;
}

ll psum(int n, int x) {
    if (x == -1) return 0;
    if (Psum[n][x] != -1) return Psum[n][x];
    return Psum[n][x] = (psum(n, x - 1) + dp(n, x)) % mod;
}

void solve(int tc) {

    while (1) {
        cin >> N >> D >> X;
        if (N == 0) break;
        if (X == 1) {
            cout << 0 << endl;
            continue;
        }
        for (int i = 0; i <= 2000; i++) {
            for (int j = 0; j <= 2000; j++) {
                DP[i][j] = Psum[i][j] = -1;
            }
        }

        ll ans = 0;
        ll ret = 1;
        for (int i = 1; i <= min(N, D); i++) {
            ret *= (D - i + 1) % mod;
            ret %= mod;
            ret *= modinv(i, mod);
            ret %= mod;
            ans += ret * dp(i, N - i) % mod;
            ans %= mod;
        }

        cout << ans << endl;

    }


    





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