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

ll F[100001];
ll Finv[100001];

void solve(int tc) {

    int N;
    cin >> N;

    ll mod = 1e9 + 7;

    F[0] = 1;
    for (ll i = 1; i <= N; i++) {
        F[i] = F[i - 1] * i % mod;
    }
    Finv[N] = modinv(F[N], mod);
    for (ll i = N - 1; i >= 0; i--) {
        Finv[i] = Finv[i + 1] * (i + 1) % mod;
    }

    vector<ll> cnt(26, 0);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        cnt[x] += 1;
    }


    vector<ll> DP1(279973, 0); // 277200
    vector<ll> DP2(97543, 0);  // 96577
    DP1[0] = DP2[0] = 1;

    for (ll i = 1; i <= 25; i++) {
        if (i == 13 || i == 17 || i == 19 || i == 23) {
            vector<ll> nx2 = DP2;
            for (ll j = 1; j <= cnt[i] && 96577 / i * j <= 97542; j++) {
                ll val = 96577ll / i * j;
                ll n = F[cnt[i]] * Finv[j] % mod * Finv[cnt[i] - j] % mod;
                for (ll k = 0; k + val <= 97542; k++) {
                    nx2[k + val] += DP2[k] * n % mod;
                    nx2[k + val] %= mod;
                }
            }
            DP2 = nx2;
        }
        else {
            vector<ll> nx1 = DP1;
            for (ll j = 1; j <= cnt[i] && 277200 / i * j <= 279972; j++) {
                ll val = 277200ll / i * j;
                ll n = F[cnt[i]] * Finv[j] % mod * Finv[cnt[i] - j] % mod;
                for (ll k = 0; k + val <= 279972; k++) {
                    nx1[k + val] += DP1[k] * n % mod;
                    nx1[k + val] %= mod;
                }
            }
            DP1 = nx1;
        }
    }

    ll ans = 0;

    ll l = 97542; ll r = 97542;
    ll psum = 0;
    for (ll i = 0; i < 279973; i++) {

        while (l != -1 && l * 277200 + i * 96577 >= 277200ll * 96577ll / 100 * 99) {
            psum += DP2[l];
            psum %= mod;
            l -= 1;
        }
        while (r != -1 && r * 277200 + i * 96577 > 277200ll * 96577ll / 100 * 101) {
            psum += mod - DP2[r];
            psum %= mod;
            r -= 1;
        }

        ans += DP1[i] * psum % mod;
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