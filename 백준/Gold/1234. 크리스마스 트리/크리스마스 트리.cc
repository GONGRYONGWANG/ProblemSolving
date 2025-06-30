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
#define INF ll(4e18)
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

ll comb[11][11];

ll DP[11][101][101][101];
ll dp(int n, int a, int b, int c) {
    if (n == 0) return 1;
    if (DP[n][a][b][c] != -1) return DP[n][a][b][c];
    ll ret = 0;
    if (a >= n) ret += dp(n - 1, a - n, b, c);
    if (b >= n) ret += dp(n - 1, a, b - n, c);
    if (c >= n) ret += dp(n - 1, a, b, c - n);
    if (n % 2 == 0) {
        if (a >= n / 2 && b >= n / 2) ret += dp(n - 1, a - n / 2, b - n / 2, c) * comb[n][n / 2];
        if (b >= n / 2 && c >= n / 2) ret += dp(n - 1, a, b - n / 2, c - n / 2) * comb[n][n / 2];
        if (c >= n / 2 && a >= n / 2) ret += dp(n - 1, a - n / 2, b, c - n / 2) * comb[n][n / 2];
    }
    if (n % 3 == 0 && a >= n / 3 && b >= n / 3 && c >= n / 3) ret += dp(n - 1, a - n / 3, b - n / 3, c - n / 3) * comb[n][n / 3] * comb[n / 3 * 2][n / 3];
    return DP[n][a][b][c] = ret;
}

void solve(int tc) {
    int N, a, b, c;
    cin >> N >> a >> b >> c;
    for (int n = 1; n <= N; n++) {
        for (int i = 0; i <= a; i++) {
            for (int j = 0; j <= b; j++) {
                for (int k = 0; k <= c; k++) {
                    DP[n][i][j][k] = -1;
                }
            }
        }
    }

    comb[0][0] = 1;
    for (int i = 1; i <= 10; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }

    cout << dp(N, a, b, c);





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