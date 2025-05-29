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

int board[52][52];
bool visited[52][52];

struct cmp {
    bool operator()(vector<int>& a, vector<int>& b) {
        return a[2] > b[2];
    }
};

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    pq<vector<int>, vector<vector<int>>, cmp> q;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char x;
            cin >> x;
            board[i][j] = x - '0';
            if (i == 1 || i == N || j == 1 || j == M) q.push({ i,j,board[i][j] });
        }
    }

    int ans = 0;
    while (!q.empty()) {
        int x = q.top()[0];
        int y = q.top()[1];
        q.pop();
        if (visited[x][y]) continue;
        visited[x][y] = true;
        int mn = 10;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir]; int ny = y + dy[dir];
            if (visited[nx][ny] || nx == 0 || ny == 0 || nx == N + 1 || ny == M + 1) {
                mn = min(board[nx][ny], mn);
                continue;
            }
            q.push({ nx,ny,board[nx][ny] });
        }

        mn = max(mn, board[x][y]);
        ans += max(0, mn - board[x][y]);
        board[x][y] = mn;
    }

    cout << ans;






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