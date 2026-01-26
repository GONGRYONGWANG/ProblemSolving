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

ll powmod(ll x, ll n, ll mod) {
    if (n == 0) return 1;
    if (n % 2) return x * powmod(x, n - 1, mod) % mod;
    ll half = powmod(x, n / 2, mod);
    return half * half % mod;
}
ll modinv(ll x, ll mod) { // when mod is primenum
    x %= mod;
    return powmod(x, mod - 2, mod);
}


ll mod = 998244353;
ll F[1000001];
ll Finv[1000001];
ll DP[1000001];


ll catalan(ll n) {
    return F[2 * n] * Finv[n] % mod * Finv[n] % mod * modinv(n + 1, mod) % mod;
}

void solve(int tc) {

    if (tc == 1) {

        F[0] = 1;
        for (int i = 1; i <= 1000000; i++) {
            F[i] = F[i - 1] * i % mod;
        }
        Finv[1000000] = modinv(F[1000000], mod);
        for (int i = 1000000; i >= 1; i--) {
            Finv[i - 1] = Finv[i] * i % mod;
        }

        DP[0] = 1;
        DP[1] = 0;
        for (int i = 2; i <= 1000000; i++) {
            DP[i] = DP[i - 2] + DP[i - 1];
            if (i % 6 == 1 || i % 6 == 4) {
                DP[i] -= catalan(i / 3);
            }
            DP[i] = (DP[i] + mod) % mod;
        }
    }

    int N;
    cin >> N;
    if (DP[N] == 0) cout << -1;
    else cout << DP[N];
    cout << endl;


    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    rng_init();
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}