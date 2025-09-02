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

int board[1001][1001];
int X[1000001];
int Y[1000001];

bool ingrid[1000002];

void solve(int tc) {
    
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
            X[board[i][j]] = i;
            Y[board[i][j]] = j;
        }
    }

    int ret = 1;
    int l = X[1], r = X[1];
    int a = Y[1], b = Y[1];
    int mx = 1;

    ingrid[1] = true;
    int nx = 2;

    while (nx <= N * N) {
        int s = X[nx], e = X[nx];
        int c = Y[nx], d = Y[nx];
        while (s < l) {
            l -= 1;
            for (int j = a; j <= b; j++) {
                mx = max(mx, board[l][j]);
                ingrid[board[l][j]] = true;
            }
        }
        while (r < e) {
            r += 1;
            for (int j = a; j <= b; j++) {
                mx = max(mx, board[r][j]);
                ingrid[board[r][j]] = true;
            }
        }
        while (c < a) {
            a -= 1;
            for (int i = l; i <= r; i++) {
                mx = max(mx, board[i][a]);
                ingrid[board[i][a]] = true;
            }
        }
        while (b < d) {
            b += 1;
            for (int i = l; i <= r; i++) {
                mx = max(mx, board[i][b]);
                ingrid[board[i][b]] = true;
            }
        }

        while (ingrid[nx]) nx += 1;

        if ((r - l + 1) * (b - a + 1) == mx) ret += 1;
    }

    cout << ret;


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