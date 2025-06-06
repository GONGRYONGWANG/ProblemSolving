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

int dx_8[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy_8[8] = { 1,2,2,1,-1,-2,-2,-1 };

int ind[750][750];
bool knight[750][750];
bool visited[750][750];

void solve(int tc) {

    int N, M;
    cin >> N >> M;
    
    pii s, e;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char x;
            cin >> x;
            if (x == 'K') {
                knight[i][j] = true;
                for (int dir = 0; dir < 8; dir++) {
                    int nx = i + dx_8[dir]; int ny = j + dy_8[dir];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    ind[nx][ny] += 1;
                }
            }
            else if (x == 'T') e = { i,j };
            else if (x == 'R') s = { i,j };
        }
    }

    queue<pii> q;
    q.push(s);
    visited[s.first][s.second] = true;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (knight[x][y]) {
            for (int dir = 0; dir < 8; dir++) {
                int nx = x + dx_8[dir]; int ny = y + dy_8[dir];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                ind[nx][ny] -= 1;
                if (ind[nx][ny] != 0) continue;

                bool flag = false;
                for (int dir2 = 0; dir2 < 4; dir2++) {
                    int nnx = nx + dx[dir2]; int nny = ny + dy[dir2];
                    while (nnx >= 0 && nnx < N && nny >= 0 && nny < M) {
                        flag |= visited[nnx][nny];
                        if (knight[nnx][nny]) break;
                        nnx += dx[dir2]; nny += dy[dir2];
                    }
                }
                if (flag) {
                    visited[nx][ny] = true;
                    q.push({ nx,ny });
                }

            }
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir]; int ny = y + dy[dir];
            while (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (!visited[nx][ny] && !ind[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({ nx,ny });
                }
                if (knight[nx][ny]) break;
                nx += dx[dir]; ny += dy[dir];
            }
        }
    }

    cout << (visited[e.first][e.second] ? "yes" : "no");







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