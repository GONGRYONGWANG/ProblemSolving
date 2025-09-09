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


//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

int DP[10][10][10];

void solve(int tc) {

    int N;
    cin >> N;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                DP[i][j][k] = inf;
            }
        }
    }
    DP[0][0][0] = 0;

    while (N--) {
        int t; cin >> t;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    DP[k][i][j] = min(DP[k][i][j], DP[(k + 1) % 10][i][j] + 1);
                    DP[i][k][j] = min(DP[i][k][j], DP[i][(k + 1) % 10][j] + 1);
                    DP[i][j][k] = min(DP[i][j][k], DP[i][j][(k + 1) % 10] + 1);
                    DP[k][i][j] = min(DP[k][i][j], DP[(k + 9) % 10][i][j] + 1);
                    DP[i][k][j] = min(DP[i][k][j], DP[i][(k + 9) % 10][j] + 1);
                    DP[i][j][k] = min(DP[i][j][k], DP[i][j][(k + 9) % 10] + 1);
                }
                for (int k = 0; k < 10; k++) {
                    DP[k][i][j] = min(DP[k][i][j], DP[(k + 1) % 10][i][j] + 1);
                    DP[i][k][j] = min(DP[i][k][j], DP[i][(k + 1) % 10][j] + 1);
                    DP[i][j][k] = min(DP[i][j][k], DP[i][j][(k + 1) % 10] + 1);
                    DP[k][i][j] = min(DP[k][i][j], DP[(k + 9) % 10][i][j] + 1);
                    DP[i][k][j] = min(DP[i][k][j], DP[i][(k + 9) % 10][j] + 1);
                    DP[i][j][k] = min(DP[i][j][k], DP[i][j][(k + 9) % 10] + 1);
                }
                for (int k = 0; k < 10; k++) {
                    DP[k][i][j] = min(DP[k][i][j], DP[(k + 1) % 10][i][j] + 1);
                    DP[i][k][j] = min(DP[i][k][j], DP[i][(k + 1) % 10][j] + 1);
                    DP[i][j][k] = min(DP[i][j][k], DP[i][j][(k + 1) % 10] + 1);
                    DP[k][i][j] = min(DP[k][i][j], DP[(k + 9) % 10][i][j] + 1);
                    DP[i][k][j] = min(DP[i][k][j], DP[i][(k + 9) % 10][j] + 1);
                    DP[i][j][k] = min(DP[i][j][k], DP[i][j][(k + 9) % 10] + 1);
                }
                for (int k = 0; k < 10; k++) {
                    DP[k][i][j] = min(DP[k][i][j], DP[(k + 1) % 10][i][j] + 1);
                    DP[i][k][j] = min(DP[i][k][j], DP[i][(k + 1) % 10][j] + 1);
                    DP[i][j][k] = min(DP[i][j][k], DP[i][j][(k + 1) % 10] + 1);
                    DP[k][i][j] = min(DP[k][i][j], DP[(k + 9) % 10][i][j] + 1);
                    DP[i][k][j] = min(DP[i][k][j], DP[i][(k + 9) % 10][j] + 1);
                    DP[i][j][k] = min(DP[i][j][k], DP[i][j][(k + 9) % 10] + 1);
                }
            }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    if (i != t && j != t && k != t) DP[i][j][k] = inf;
                }
            }
        }

    }

    int ans = inf;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                ans = min(ans, DP[i][j][k]);
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