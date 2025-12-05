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


int psum[4001][4001];
int board[4001][4001];
int cal(int l, int r) {
    return board[r][r] - board[l - 1][r] - board[r][l - 1] + board[l - 1][l - 1];
}

int DP[4001][4001];
void dnc(int s, int e, int l, int r, int k) {
    if (e < s) return;
    int m = (s + e) / 2;
    int opt = l;
    for (int i = l; i <= min(r, m); i++) {
        if (DP[k - 1][opt - 1] + cal(opt, m) > DP[k - 1][i - 1] + cal(i, m)) opt = i;
    }

    DP[k][m] = DP[k - 1][opt - 1] + cal(opt, m);

    dnc(s, m - 1, l, opt, k);
    dnc(m + 1, e, opt, r, k);
}


void solve(int tc) {
    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> psum[i][j];
            psum[i][j] += psum[i][j - 1];
            board[i][j] = board[i - 1][j] + psum[i][j];
        }
    }


    for (int i = 1; i <= N; i++) {
        DP[1][i] = cal(1, i);
    }

    for (int k = 2; k <= K; k++) {
        dnc(1, N, 1, N, k);
    }

    cout << DP[K][N] / 2;




    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    // fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}