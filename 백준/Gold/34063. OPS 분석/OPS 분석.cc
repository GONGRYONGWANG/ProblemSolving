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
///////////////////////////////////////////////////////////////


ll DP[81][321];
ll comb[81][81];
ll mod = 20150116;

void solve(int tc) {

    ll N;
    cin >> N;

    ld p;
    cin >> p;
    ll P = p * 1000;

    DP[0][0] = 1;
    for (int n = 1; n <= N; n++) {
        for (int j = 1; j <= 4; j++) {
            for (int i = j; i <= n * 4; i++) {
                DP[n][i] += DP[n - 1][i - j];
                DP[n][i] %= mod;
            }
        }
    }

    for (int n = 0; n <= N; n++) {
        comb[n][0] = 1;
        for (int c = 1; c <= n; c++) {
            comb[n][c] = comb[n - 1][c] + comb[n - 1][c - 1];
            comb[n][c] %= mod;
        }
    }

    ll ans = 0;

    for (int e = 0; e < N; e++) {
        for (int f = 0; f <= N - e; f++) {
            ll n = N - e - f;
            for (int i = n; i <= 4 * n; i++) {
                ll ret = comb[N][e] * comb[N - e][f] % mod * DP[n][i] % mod;
                if (((N - f) * (N - e) + N * i) * 1000 >= P * N * (N - e)) ans += ret;
                ans %= mod;
            }
        }
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