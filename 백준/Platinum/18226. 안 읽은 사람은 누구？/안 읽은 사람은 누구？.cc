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
ll mod = 1e9 + 7;

ll comb(int n, int r) {
    return F[n] * Finv[n - r] % mod * Finv[r] % mod;
}

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    F[0] = 1;
    for (int i = 1; i <= N; i++) {
        F[i] = F[i - 1] * i % mod;
    }

    Finv[N] = modinv(F[N], mod);
    for (int i = N; i >= 1; i--) {
        Finv[i - 1] = Finv[i] * i % mod;
    }

    vector<int> cnt(N + 1, 0);
    vector<pii> arr(M);
    for (int i = 0; i < M; i++) {
        cin >> arr[i].first >> arr[i].second;
        cnt[arr[i].first] += 1;
    }

    for (int i = M - 1; i > 0; i--) {
        if (arr[i].second < arr[i - 1].second) {
            cout << 0;
            return;
        }
        arr[i].second -= arr[i - 1].second;
    }

    int x = 0;
    for (int i = 1; i <= N; i++) {
        if (cnt[i] == 0) x += 1;
    }

    ll ans = 1;

    for (auto [a, b] : arr) {
        if (b > x) {
            cout << 0;
            return;
        }
        ans = ans * comb(x, b) % mod;
        x -= b;
        cnt[a] -= 1;
        if (cnt[a] == 0) x += 1;
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