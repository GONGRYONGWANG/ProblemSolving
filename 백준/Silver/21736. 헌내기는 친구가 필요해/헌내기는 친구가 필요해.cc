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

char board[600][600];
bool visited[600][600];

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    pii s;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        cin >> board[i][j];
        if (board[i][j] == 'I') s = { i,j };
    }

    queue<pii> q;
    q.push(s);
    visited[s.first][s.second] = true;

    int ans = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (board[x][y] == 'P') ans += 1;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir]; int ny = y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (visited[nx][ny]) continue;
            if (board[nx][ny] == 'X') continue;
            visited[nx][ny] = true;
            q.push({ nx,ny });
        }
    }

    if (ans == 0) cout << "TT";
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