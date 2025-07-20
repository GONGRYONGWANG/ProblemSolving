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
    



int DP[17][80][80][160];

void solve(int tc) {

    int N;
    cin >> N;

    for (int a = 0; a < 80; a++) {
        for (int b = 0; b < 80; b++) {
            for (int c_d = 0; c_d < 160; c_d++) {
                DP[0][a][b][c_d] = -inf;
            }
        }
    }

    DP[0][0][0][80] = 0;

    for (int i = 1; i <= N; i++) {
        int x; cin >> x;

        for (int a = 0; a < 80; a++) {
            for (int b = 0; b < 80; b++) {
                for (int c_d = 0; c_d < 160; c_d++) {
                    DP[i][a][b][c_d] = -inf;
                }
            }
        }

        for (int a = 0; a < 80; a++) {
            for (int b = 0; b < 80; b++) {
                for (int c_d = 0; c_d < 160; c_d++) {
                    DP[i][a][b][c_d] = max(DP[i][a][b][c_d], DP[i - 1][a][b][c_d]);
                    if (a + x < 80) DP[i][a + x][b][c_d] = max(DP[i][a + x][b][c_d], DP[i - 1][a][b][c_d]);
                    if (b + x < 80) DP[i][a][b + x][c_d] = max(DP[i][a][b + x][c_d], DP[i - 1][a][b][c_d]);
                    if (c_d + x < 160) DP[i][a][b][c_d + x] = max(DP[i][a][b][c_d + x], DP[i - 1][a][b][c_d]);
                    if (c_d - x >= 0) DP[i][a][b][c_d - x] = max(DP[i][a][b][c_d - x], DP[i - 1][a][b][c_d] + x);
                }
            }
        }
    }

    int ans = -1;
    for (int a = 1; a < 80; a++) {
        if (DP[N][a][a][80] > 0) ans = max(ans, DP[N][a][a][80] * a);
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