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
#define INF ll(9e18)
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


int board[101][101];
int DP[101][101];

void solve(int tc) {

    int H, W, O, F;
    cin >> H >> W >> O >> F;

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            board[i][j] = 0;
            DP[i][j] = -1;
        }
    }

    pii s, e;
    cin >> s.first >> s.second;
    cin >> e.first >> e.second;

    while (O--) {
        int x, y, L;
        cin >> x >> y >> L;
        board[x][y] = L;
    }

    queue<pii> q;
    q.push(s);
    DP[s.first][s.second] = F;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (DP[x][y] == 0) continue;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir]; int ny = y + dy[dir];
            if (nx <= 0 || nx > H || ny <= 0 || ny > W) continue;
            if (DP[nx][ny] != -1) continue;
            if (board[nx][ny] - board[x][y] > DP[x][y]) continue;
            q.push({ nx,ny });
            DP[nx][ny] = DP[x][y] - 1;
        }
    }

    if (DP[e.first][e.second] != -1) cout << "잘했어!!";
    else cout << "인성 문제있어??";
    cout << endl;



}
    



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    cin >> T;
    //fin.open("input.txt"); fout.open("output.txt");
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}