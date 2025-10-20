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
const long double pi = acosl(-1);
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()

#include<fstream>
ifstream fin; ofstream fout;

//#define cin fin 
//#define cout fout

//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


int N, K;
int DP[41][2][2][2];
int dp(int x, int p, int c, int k) {
    if (x == N + 1) return 1;
    if (DP[x][p][c][k] != -1) return DP[x][p][c][k];

    if (x - 1 == K && k) p = true;
    if (x == K && k) c = true;

    if (x == K) return dp(x + 1, c, false, k);

    
    int ret = 0;
    if (!p) {
        if (x - 1 == K) ret += dp(x + 1, c, false, true);
        else ret += dp(x + 1, c, false, k);
    }
    if (!c) {
        if (x == K) ret += dp(x + 1, true, false, true);
        else ret += dp(x + 1, true, false, k);
    }
    if (x + 1 != K && x != N) {
        ret += dp(x + 1, c, true, k);
    }
    if (!k && K != x && K != x - 1) {
        ret += dp(x + 1, c, false, true);
    }
    return DP[x][p][c][k] = ret;
}

void solve(int tc) {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int c = 0; c < 2; c++) {
                    DP[i][j][c][k] = -1;
                }
            }
        }
    }

    cout << dp(1, 1, 0, 0);

    // cout << "Case #" << tc << ": " << ret<< endl;
}

int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}