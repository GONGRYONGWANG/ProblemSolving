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

ll mod = 1e9 + 7;
ll F[101];
ll Finv[101];

void solve(int tc) {

    int N, K;
    cin >> N >> K;

    F[0] = Finv[0] = 1;
    for (int i = 1; i <= 100; i++) {
        F[i] = F[i - 1] * i % mod;
        Finv[i] = modinv(F[i], mod);
    }


    vector<int> arr(K);
    for (int i = 0; i < K; i++) cin >> arr[i];

    ll ret = 1;

    int l = 1;
    int r = 100;
    for (int i = 0; i < K - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            ret *= F[arr[i] - l] * Finv[(N - 1) / 2] % mod * Finv[arr[i] - l - (N - 1) / 2] % mod;
            ret %= mod;
            N -= (N + 1) / 2;
            l = arr[i] + 1;
        }
        else {
            ret *= F[r - arr[i]] * Finv[N / 2] % mod * Finv[r - arr[i] - N / 2] % mod;
            ret %= mod;
            N -= N / 2 + 1;
            r = arr[i] - 1;
        }
    }
    
    ret *= F[arr.back() - l] * Finv[(N - 1) / 2] % mod * Finv[arr.back() - l - (N - 1) / 2] % mod;
    ret %= mod;
    ret *= F[r - arr.back()] * Finv[N / 2] % mod * Finv[r - arr.back() - N / 2] % mod;
    ret %= mod;

    cout << ret;







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
