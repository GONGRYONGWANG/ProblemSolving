// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
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



char board[7][7];
int visited[7][7][(1 << 7)][(1 << 7)];

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    if (board[0][0] == 'B') {
        cout << -1;
        return;
    }

    queue<tuple<int,int,int,int>> q;
    q.push({ 0,0,0,0});
    visited[0][0][0][0] = 1;
    while (!q.empty()) {
        auto [x, y, bitx, bity] = q.front();
        q.pop();

        int d = visited[x][y][bitx][bity];

        if (x == N - 1 && y == M - 1) {
            cout << d - 1;
            return;
        }

        if (!visited[x][y][bitx ^ (1 << x)][bity ^ (1 << y)]) {
            visited[x][y][bitx ^ (1 << x)][bity ^ (1 << y)] = d + 1;
            q.push({ x,y,bitx ^ (1 << x),bity ^ (1 << y) });
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir]; int ny = y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] == 'B') continue;
            if (visited[nx][ny][bitx][bity]) continue;
            if (board[x][y] != 'A' && (dir % 2) ^ (board[x][y] == 'C') ^ !(bool(bitx & (1 << x)) ^ bool(bity & (1 << y)))) continue;
            if (board[nx][ny] != 'A' && (dir % 2) ^ (board[nx][ny] == 'C') ^ !(bool(bitx & (1 << nx)) ^ bool(bity & (1 << ny)))) continue;
            q.push({ nx,ny,bitx,bity });
            visited[nx][ny][bitx][bity] = d + 1;
        }
    }

    cout << -1;






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