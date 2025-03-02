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
const ll INF = 1e18 + 7;
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

int board[1001][1001];
pii parent[1001][1001];
int wet[1001][1001];
pii findp(pii p) {
    auto [x, y] = p;
    if (parent[x][y] == p) return p;
    return parent[x][y] = findp(parent[x][y]);
}



void solve(int tc) {

    int N, M, Q;
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
            parent[i][j] = { i,j };
        }
    }

    for (int t = 1; t <= Q; t++) {
        int a, b, c;
        cin >> a >> b >> c;
        board[a][b] -= c;
        if (wet[a][b]) {
            wet[a][b] = t;
            auto [x, y] = findp({ a,b });
            if (board[a][b] < board[x][y]) {
                parent[x][y] = { a,b };
                parent[a][b] = { a,b };
            }
        }
        else {
            wet[a][b] = t;
            for (int dir = 0; dir < 4; dir++) {
                int nx = a + dx[dir]; int ny = b + dy[dir];
                if (nx <= 0 || nx > N || ny <= 0 || ny > M) continue;
                if (!wet[nx][ny]) continue;
                auto [p, q] = findp({ a,b }); auto [r, s] = findp({ nx,ny });
                if (findp({ a,b }) == findp({ nx,ny })) continue;
                if (board[p][q] < board[r][s]) parent[r][s] = { p,q };
                else if (board[p][q] == board[r][s] && wet[p][q] < wet[r][s]) parent[r][s] = { p,q };
                else parent[p][q] = { r,s };
            }
        }
        pii ret = findp({ a,b });
        cout << ret.first << " " << ret.second << endl;
    }






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