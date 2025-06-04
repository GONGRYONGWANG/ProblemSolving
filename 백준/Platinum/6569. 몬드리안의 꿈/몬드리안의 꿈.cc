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
///////////////////////////////////////////////////////////////

int N, M;
ll DP[11][11][(1 << 11)];
ll dp(int x, int y, int bit) {
    if (x == N) {
        if (bit != 0) return 0;
        else return 1;
    }
    if (y == M) return dp(x + 1, 0, bit);
    if (DP[x][y][bit] != -1) return DP[x][y][bit];
    if (bit & (1 << y)) return DP[x][y][bit] = dp(x, y + 1, bit ^ (1 << y));
    DP[x][y][bit] = dp(x, y + 1, bit | (1 << y));
    if (y != M - 1 && !(bit & (1 << (y + 1)))) DP[x][y][bit] += dp(x, y + 2, bit);
    return DP[x][y][bit];
}

void solve(int tc) {

    while (1) {
        cin >> N >> M;
        if (N == 0) return;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int bit = 0; bit < (1 << M); bit++) {
                    DP[i][j][bit] = -1;
                }
            }
        }

        cout << dp(0, 0, 0) << endl;
    }



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