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
const long double pi = 3.14159265358979323846;
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

int W, L;
ll DP[1001][1000][2][2];
ll mod = 1e9 + 7;
ll dp(int x, int n, bool l, bool r) {
    if (x < 0 || x >= L - 1) return 0;
    if (x == 0) l = true;
    if (x == L - 2) r = true;

    if (n == 0) {
        if (l && r) return 1;
        else return 0;
    }

    if (DP[x][n][l][r] != -1) return DP[x][n][l][r];

    return DP[x][n][l][r] = (dp(x - 1, n - 1, l, r) + dp(x, n - 1, l, r) + dp(x + 1, n - 1, l, r)) % mod;

}

void solve(int tc) {

    cin >> W >> L;

    for (int i = 0; i < L - 1; i++) {
        for (int j = 0; j <= W; j++) {
            for (int l = 0; l < 2; l++) {
                for (int r = 0; r < 2; r++) {
                    DP[i][j][l][r] = -1;
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < L; i++) {
        ans += dp(i, W - 1, false, false);
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