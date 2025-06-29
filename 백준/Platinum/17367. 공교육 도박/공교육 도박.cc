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
///////////////////////////////////////////////////////////////

ld DP[1001][7][7][7];
ld dp(int n, int a, int b, int c) {
    if (DP[n][a][b][c] != 0) return DP[n][a][b][c];

    if (a == b && a == c) DP[n][a][b][c] = 10000 + a * 1000;
    else if (a == b || a == c) DP[n][a][b][c] = 1000 + 100 * a;
    else if (b == c) DP[n][a][b][c] = 1000 + 100 * b;
    else DP[n][a][b][c] = max(max(a, b), c) * 100;

    if (n == 0) return DP[n][a][b][c];

    ld ret = 0;
    for (int i = 1; i <= 6; i++) {
        ret += dp(n - 1, b, c, i);
    }
    ret /= 6;

    return DP[n][a][b][c] = max(DP[n][a][b][c], ret);

}

void solve(int tc) {

    int N;
    cin >> N;

    ld ans = 0;
    for (int a = 1; a <= 6; a++) {
        for (int b = 1; b <= 6; b++) {
            for (int c = 1; c <= 6; c++) {
                ans += dp(N - 3, a, b, c);
            }
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << ans / 216;

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