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

ll mod = 1e9 + 7;
ll F[500001];
ll Finv[500001];

void solve(int tc) {

    F[0] = 1;
    for (ll i = 1; i <= 500000; i++) {
        F[i] = F[i - 1] * i % mod;
    }

    Finv[500000] = modinv(F[500000], mod);

    for (ll i = 500000; i >= 1; i--) {
        Finv[i - 1] = Finv[i] * i % mod;
    }

    int N;
    cin >> N;

    ll total = 0;

    vector<ll> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        total += arr[i];
    }

    vector<ll> A(N), B(N), C(N), D(N);
    A[0] = 1; C[0] = 1;
    ll psum = 0;
    for (int i = 1; i < N; i++) {
        psum += arr[i - 1];
        A[i] = A[i - 1] * F[psum] % mod * Finv[arr[i - 1]] % mod * Finv[psum - arr[i - 1]] % mod;
        C[i] = F[total] * Finv[psum] % mod * Finv[total - psum] % mod;
    }

    B[N - 1] = 1; D[N - 1] = 1;
    psum = 0;
    for (int i = N - 2; i >= 0; i--) {
        psum += arr[i + 1];
        B[i] = B[i + 1] * F[psum] % mod * Finv[arr[i + 1]] % mod * Finv[psum - arr[i + 1]] % mod;
        if (arr[i] == 0) D[i] = 0;
        else D[i] = F[psum + arr[i] - 1] * Finv[psum] % mod * Finv[arr[i] - 1] % mod;
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += A[i] * B[i] % mod * C[i] % mod * D[i] % mod;
        ans %= mod;
    }

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