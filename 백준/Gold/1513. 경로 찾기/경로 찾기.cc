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

int board[51][51];
ll DP[51][51][51][51]; // x,y,n,k
ll mod = 1e6 + 7;

void solve(int tc) {

    int N, M, C;
    cin >> N >> M >> C;
    
    for (int i = 0; i < C; i++ ) {
        int x, y;
        cin >> x >> y;
        board[x][y] = i + 1;
    }

    DP[1][0][0][0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (board[i][j] == 0) {
                for (int n = 0; n <= C; n++) {
                    for (int k = 0; k <= C; k++) {
                        DP[i][j][n][k] = (DP[i - 1][j][n][k] + DP[i][j - 1][n][k]) % mod;
                    }
                }
            }
            else {
                for (int n = 0; n < C; n++) {
                    for (int k = 0; k < board[i][j]; k++){
                        DP[i][j][n + 1][board[i][j]] += (DP[i - 1][j][n][k] + DP[i][j - 1][n][k]) % mod;
                        DP[i][j][n + 1][board[i][j]] %= mod;
                    }
                }
            }
        }
    }

    for (int n = 0; n <= C; n++) {
        ll ret = 0;
        for (int k = 0; k <= C; k++) {
            ret += DP[N][M][n][k];
            ret %= mod;
        }
        cout << ret << " ";
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