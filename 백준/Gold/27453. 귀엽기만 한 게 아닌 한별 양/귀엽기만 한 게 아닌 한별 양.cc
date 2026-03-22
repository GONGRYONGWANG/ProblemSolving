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
const long double pi = acosl(-1);
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()

#include<random> // rand
std::mt19937 gen;
void rng_init() {
    std::random_device rd;
    gen.seed(rd());  // main에서 1번
}
int randint(int l, int r) {
    std::uniform_int_distribution<int> dist(l, r);
    return dist(gen);
}

#include<fstream>
ifstream fin; ofstream fout;

//#define cin fin 
//#define cout fout

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

int board[1000][1000];
int visited[1000][1000][4];

void solve(int tc) {

    int N, M, K;
    cin >> N >> M >> K;

    pii s, e;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c; cin >> c;
            if (c == 'S') {
                s = { i,j };
            }
            else if (c == 'H') {
                e = { i,j };
            }
            else if (c == 'X') board[i][j] = K + 1;
            else board[i][j] = (c - '0');
        }
    }

    queue<tuple<int, int, int>> q;
    for (int dir = 0; dir < 4; dir++) {
        int nx = s.first + dx[dir];
        int ny = s.second + dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (board[nx][ny] > K) continue;
        q.push({ nx,ny,dir });
        visited[nx][ny][dir] = 2;
    }

    while (!q.empty()) {
        auto [x, y, d] = q.front();
        q.pop();
        if (x == e.first && y == e.second) {
            cout << visited[x][y][d] - 1;
            return;
        }
        int k = board[x][y] + board[x - dx[d]][y - dy[d]];
        for (int dir = 0; dir < 4; dir++) {
            if (dir == (d + 2) % 4) continue;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (k + board[nx][ny] > K) continue;
            if (visited[nx][ny][dir]) continue;
            q.push({ nx,ny,dir });
            visited[nx][ny][dir] = visited[x][y][d] + 1;
        }
    }

    cout << -1;


    // cout << "Case #" << tc << ": " << ret << endl;
}   


int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    rng_init();
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}