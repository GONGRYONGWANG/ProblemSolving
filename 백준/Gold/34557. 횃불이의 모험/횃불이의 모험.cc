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

int board[101][101];
bool go(string e, bool prv, bool cur) {
    if (e == "Down" && !prv && cur) return true;
    if (e == "Stay" && prv && cur) return true;
    if (e == "Up" && prv && !cur) return true;
    return false;
}

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    int x, y;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                x = i; y = j;
                board[i][j] = 0;
            }
        }
    }

    vector<string> ev(4);
    for (int i = 0; i < 4; i++) {
        cin >> ev[i];
    }

    string s;
    cin >> s;
    vector<bool> hold = { 0,0,0,0 };
    for (char c : s) {

        vector<bool> nxhold = { 0,0,0,0 };
        if (c == 'W') nxhold[0] = true;
        if (c == 'A') nxhold[1] = true;
        if (c == 'S') nxhold[2] = true;
        if (c == 'D') nxhold[3] = true;

        x -= (x != 1 && !board[x - 1][y] && go(ev[0], hold[0], nxhold[0]));
        y -= (y != 1 && !board[x][y - 1] && go(ev[1], hold[1], nxhold[1]));
        x += (x != N && !board[x + 1][y] && go(ev[2], hold[2], nxhold[2]));
        y += (y != N && !board[x][y + 1] && go(ev[3], hold[3], nxhold[3]));

        hold = nxhold;

    }


    cout << x << " " << y;

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