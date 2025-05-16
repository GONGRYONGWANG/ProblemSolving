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

int visited[22][22][22][22];
bool board[22][22];

void solve(int tc) {
    int N, M;
    cin >> N >> M;

    int sx1 = -1, sx2, sy1, sy2;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char x;
            cin >> x;
            board[i][j] = (x == '#');
            if (x == 'o') {
                if (sx1 == -1) sx1 = i, sy1 = j;
                else sx2 = i, sy2 = j;
            }
        }
    }

    queue<vector<int>> q;
    q.push({ sx1,sy1,sx2,sy2 });
    visited[sx1][sy1][sx2][sy2] = 1;
    while (!q.empty()) {
        int x1 = q.front()[0]; int y1 = q.front()[1];
        int x2 = q.front()[2]; int y2 = q.front()[3];
        q.pop();

        int d = visited[x1][y1][x2][y2];

        if (d - 1 > 10) continue;

        if ((x1 <= 0 || x1 > N) && (x2 <= 0 || x2 > N)) continue;
        else if (x1 <= 0 || x1 > N || x2 <= 0 || x2 > N) {
            cout << d - 1;
            return;
        }

        if ((y1 <= 0 || y1 > M) && (y2 <= 0 || y2 > M)) continue;
        else if (y1 <= 0 || y1 > M || y2 <= 0 || y2 > M) {
            cout << d - 1;
            return;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx1 = x1 + dx[dir]; int ny1 = y1 + dy[dir];
            int nx2 = x2 + dx[dir]; int ny2 = y2 + dy[dir];
            if (board[nx1][ny1]) nx1 = x1, ny1 = y1;
            if (board[nx2][ny2]) nx2 = x2, ny2 = y2;
            if (visited[nx1][ny1][nx2][ny2]) continue;
            visited[nx1][ny1][nx2][ny2] = d + 1;
            q.push({ nx1,ny1,nx2,ny2 });
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