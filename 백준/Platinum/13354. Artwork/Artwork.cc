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


int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


int board[1001][1001];
pii parent[1001][1001];
pii findp(pii p) {
    auto [x, y] = p;
    if (parent[x][y] == p) return p;
    return parent[x][y] = findp(parent[x][y]);
}

void solve(int tc) {

    int N, M, Q;
    cin >> N >> M >> Q;

    vector<pair<pii, pii>> query(Q);
    for (int i = 0; i < Q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        query[i] = { {x1,y1},{x2,y2} };
        if (x1 == x2) {
            for (int j = y1; j <= y2; j++) {
                board[x1][j] += 1;
            }
        }
        else {
            for (int j = x1; j <= x2; j++) {
                board[j][y1] += 1;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            parent[i][j] = { 0,0 };
        }
    }

    int ret = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (board[i][j]) continue;
            parent[i][j] = { i,j };
            ret += 1;
            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir]; int ny = j + dy[dir];
                if (nx <= 0 || nx > N || ny <= 0 || ny > M || parent[nx][ny].first == 0) continue;
                if (findp({ i,j }) == findp({ nx,ny })) continue;
                ret -= 1;
                parent[findp({ nx,ny }).first][findp({ nx,ny }).second] = findp({ i,j });
            }
        }
    }

    vector<int> ans(Q);
    for (int q = Q - 1; q >= 0; q--) {
        ans[q] = ret;
        auto [x1, y1] = query[q].first;
        auto [x2, y2] = query[q].second;
        if (x1 == x2) {
            for (int j = y1; j <= y2; j++) {
                board[x1][j] -= 1;
                if (board[x1][j] == 0) {
                    parent[x1][j] = { x1,j };
                    ret += 1;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = x1 + dx[dir]; int ny = j + dy[dir];
                        if (nx <= 0 || nx > N || ny <= 0 || ny > M || parent[nx][ny].first == 0) continue;
                        if (findp({ x1,j }) == findp({ nx,ny })) continue;
                        ret -= 1;
                        parent[findp({ nx,ny }).first][findp({ nx,ny }).second] = { x1,j };
                    }
                }
            }
        }
        else {
            for (int j = x1; j <= x2; j++) {
                board[j][y1] -= 1;
                if (board[j][y1] == 0) {
                    parent[j][y1] = { j,y1 };
                    ret += 1;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = j + dx[dir]; int ny = y1 + dy[dir];
                        if (nx <= 0 || nx > N || ny <= 0 || ny > M || board[nx][ny]) continue;
                        if (findp({ j,y1 }) == findp({ nx,ny })) continue;
                        ret -= 1;
                        parent[findp({ nx,ny }).first][findp({ nx,ny }).second] = { j,y1 };
                    }
                }
            }
        }
    }

    for (int x : ans) cout << x << endl;





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