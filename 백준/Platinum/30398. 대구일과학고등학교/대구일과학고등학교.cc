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

ll mod = 1e9 + 7;
ll F[1000000];
ll Finv[1000000];

void solve(int tc) {

    ll N, d, P;
    cin >> N >> d >> P;
    
    F[0] = 1;
    for (ll i = 1; i < N * d; i++) {
        F[i] = F[i - 1] * i % mod;
    }
    Finv[N * d - 1] = modinv(F[N * d - 1], mod);
    for (ll i = N * d - 2; i >= 0; i--) {
        Finv[i] = Finv[i + 1] * (i + 1) % mod;
    }

    ll ans = 1;
    vector<ll> cur(d, 1);
    while (P--) {
        ll total = 0;
        for (int i = 0; i < d; i++) {
            int x;
            cin >> x;
            total += x - cur[i];
            ans *= Finv[x - cur[i]];
            ans %= mod;
            cur[i] = x;
        }
        ans *= F[total];
        ans %= mod;
    }

    ll total = 0;
    for (ll x : cur) {
        total += N - x;
        ans *= Finv[N - x];
        ans %= mod;
    }
    ans *= F[total];
    ans %= mod;
    cout << ans;



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