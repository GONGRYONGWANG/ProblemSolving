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

int dx[4] = { -1,0,1,0 }; 
int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

int N;

bool init[18][18];
bool board[18][18];

void flip(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) return;
    else board[x][y] = !board[x][y];
}

void press(int x, int y) {
    flip(x, y);
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir]; int ny = y + dy[dir];
        flip(nx, ny);
    }
}

void solve(int tc) {

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> init[i][j];
        }
    }

    int ans = inf;

    for (int bit = 0; bit < (1 << N); bit++) {

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                board[i][j] = init[i][j];
            }
        }

        int ret = 0;

        for (int j = 0; j < N; j++) {
            if (bit & (1 << j)) {
                ret += 1;
                press(0, j);
            }
        }

        for (int i = 1; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i - 1][j]) {
                    ret += 1;
                    press(i, j);
                }
            }
        }

        bool flag = false;
        for (int j = 0; j < N; j++) {
            flag |= board[N - 1][j];
        }

        if (!flag) ans = min(ans, ret);

    }

    if (ans == inf) cout << -1;
    else cout << ans;


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