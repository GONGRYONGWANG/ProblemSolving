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
int Dx[8] = { -1,-1,-1,0,1,1,1,0 };
int Dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

char init[1002][1002];
int board[1002][1002];
int sz[1000010];

unordered_set<int> E[1000010];

struct cmp {
    bool operator()(pii& a, pii& b) {
        return a.second > b.second;
    }
};

bool visited[1000010];

void solve(int tc) {

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> init[i][j];
        }
    }

    for (int i = 2; i <= N; i++) board[i][0] = 1;
    for (int j = 1; j <= N - 1; j++) board[N + 1][j] = 1;
    for (int j = 2; j <= N; j++) board[0][j] = 2;
    for (int i = 1; i <= N - 1; i++) board[i][N + 1] = 2;

    board[1][1] = board[N][N] = -1;

    int idx = 2;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (board[i][j] != 0 ) continue;
            idx += 1;
            queue<pii> q;
            q.push({ i,j });
            board[i][j] = idx;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (board[nx][ny] != 0) continue;
                    if (init[nx][ny] != init[x][y]) continue;
                    board[nx][ny] = idx;
                    q.push({ nx,ny });
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (init[i][j] == '.') continue;
            for (int dir = 0; dir < 8; dir++) {
                int nx = i + Dx[dir];
                int ny = j + Dy[dir];
                if (board[nx][ny] == 0) continue;
                if (board[nx][ny] == -1) continue;
                if (board[nx][ny] == board[i][j]) continue;
                E[board[i][j]].insert(board[nx][ny]);
                E[board[nx][ny]].insert(board[i][j]);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (board[i][j] == -1) continue;
            sz[board[i][j]] += 1;
        }
    }

    pq<pii, vector<pii>, cmp> q;
    q.push({ 1,0 });
    while (!q.empty()) {
        auto [x, d] = q.top();
        q.pop();
        if (visited[x]) continue;
        visited[x] = true;
        if (x == 2) {
            cout << d;
            return;
        }
        for (int nx : E[x]) {
            if (visited[nx]) continue;
            q.push({ nx,d + sz[nx] });
        }
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