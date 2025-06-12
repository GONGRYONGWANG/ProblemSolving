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

//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
int dx[8] = { -1,-1,-1,0,1,1,1,0 };
int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

int board[502][502];
pii parent[502][502];
pii findp(pii p) {
    auto [x, y] = p;
    if (parent[x][y] == p) return p;
    return parent[x][y] = findp(parent[x][y]);
}

int ret[502][502];

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j <= M + 1; j++) {
            if (i == 0 || j == 0 || i == N + 1 || j == M + 1) {
                board[i][j] = inf;
                continue;
            }
            cin >> board[i][j];
            parent[i][j] = { i,j };
        }
    }


    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int x = i; int y = j;
            for (int dir = 0; dir < 8; dir++) {
                int nx = i + dx[dir], ny = j + dy[dir];
                if (board[nx][ny] < board[x][y]) x = nx, y = ny;
            }
            parent[i][j] = findp({ x,y });
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            auto [x, y] = findp({ i,j });
            ret[x][y] += 1;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
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