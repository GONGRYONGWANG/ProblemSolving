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


bool board[2000][2000];
int U[2000][2000];
int L[2000][2000];
int DP[2000][2000];

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char x; cin >> x;
            board[i][j] = (x == 'X'); 
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            if (i == 0 || board[i - 1][j]) U[i][j] = 0;
            else U[i][j] = U[i - 1][j] + 1;

            if (j == 0 || board[i][j - 1]) L[i][j] = 0;
            else L[i][j] = L[i][j - 1] + 1;

        }
    }

    vector<int> ret(min(N, M) + 1, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!board[i][j]) continue;
            if (i == 0 || j == 0) DP[i][j] = 1;
            else DP[i][j] = min(min(L[i][j], U[i][j]), DP[i - 1][j - 1]) + 1;
            ret[DP[i][j]] += 1;
        }
    }

    for (int i = min(N, M)-1; i >= 1; i--) {
        ret[i] += ret[i + 1];
    }

    for (int i = 1; i <= min(N, M); i++) cout << ret[i] << endl;





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