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
ll F[100001];
ll Finv[100001];
ll oddF[100001];
ll pow2[100001];

void solve(int tc) {

    if (tc == 1) {
        F[0] = 1;
        for (ll i = 1; i <= 100000; i++) {
            F[i] = F[i - 1] * i % mod;
        }
        Finv[100000] = modinv(F[100000], mod);
        for (ll i = 100000; i >= 1; i--) {
            Finv[i - 1] = Finv[i] * i % mod;
        }

        oddF[1] = 1;
        for (ll i = 3; i <= 100000; i += 2) {
            oddF[i] = oddF[i - 2] * i % mod;
        }

        pow2[0] = 1;
        for (ll i = 1; i <= 100000; i++) {
            pow2[i] = pow2[i - 1] * 2 % mod;
        }
    }

    int N, A, B, C;
    cin >> N >> A >> B >> C;
    if (B % 2) {
        cout << 0 << endl;
        return;
    }

    if (B == 0 && C != 0) {
        cout << 0 << endl;
        return;
    }

    int b = B / 2;
    if (N < A + B + C + A + b - 1) {
        cout << 0 << endl;
        return;
    }

    int D = N - (A + B + C + A + b - 1);

    ll ret = F[A + b] * oddF[B - 1] % mod * pow2[b] % mod * F[A + b + D] % mod * Finv[A + b] % mod * Finv[D] % mod;
    if (b != 0)  ret *= F[b + C - 1] * Finv[b - 1] % mod;

    cout << ret % mod << endl;


}
    



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}