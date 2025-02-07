// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<utility>
#include<list>
#include<queue>
#include<stack>
#include<deque>
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
const ll INF = 1e18 + 7;
const int inf = 1e9 + 7;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";


//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

int DP[100][100][4];

void solve(int tc) {
    int N, M;
    cin >> N >> M;
    N -= 1; M -= 1;
    
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            for (int dir = 0; dir < 4; dir++) {
                if (i == 0 && j == 0) {
                    DP[i][j][dir] = 1;
                    continue;
                }
                if (dir == 0) {
                    if (j != 0) DP[i][j][dir] += DP[i][j - 1][3];
                    if (i != 0) DP[i][j][dir] += DP[i - 1][j][0];
                }
                else if (dir == 1) {
                    if (j != 0) DP[i][j][dir] += DP[i][j - 1][1];
                    if (i != 0) DP[i][j][dir] += DP[i - 1][j][2];
                }
                else if (dir == 2) {
                    if (i != 0) DP[i][j][dir] += DP[i - 1][j][0];
                }
                else {
                    if (j != 0) DP[i][j][dir] += DP[i][j - 1][1];
                }
                DP[i][j][dir] %= 100000;
            }
        }
    }

    cout << (DP[N - 1][M][0] + DP[N][M - 1][1]) % 100000;




}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}