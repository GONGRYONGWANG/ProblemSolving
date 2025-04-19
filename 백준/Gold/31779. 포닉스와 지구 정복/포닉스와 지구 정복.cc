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
#define INF ll(9e18)
const int inf = 1e9 + 7;
const long double pi = 3.14159265358979323846;
const string debug = "output: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;

//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

ll board[1000][1000];
pii parent[1000][1000];
pii findp(pii p) {
    if (parent[p.first][p.second] == p) return p;
    return parent[p.first][p.second] = findp(parent[p.first][p.second]);
}
bool vol[1000][1000];

void solve(int tc) {

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            parent[i][j] = { i,j };
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ll x;
            cin >> x;
            board[i][j] -= x;
            if ((i + j) % 2) board[i][j] = -board[i][j];
        }
    }



    while (K--) {
        int x, y;
        cin >> x >> y;
        x -= 1; y -= 1;
        vol[x][y] = true;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (vol[i][j]) continue;
            if (i + 1 < N && !vol[i + 1][j] && findp({ i,j }) != findp({ i + 1,j })) {
                board[findp({ i + 1,j }).first][findp({ i + 1,j }).second] += board[findp({ i,j }).first][findp({ i,j }).second];
                parent[findp({ i,j }).first][findp({ i,j }).second] = findp({ i + 1,j });
            }
            if (j + 1 < M && !vol[i][j + 1] && findp({ i,j }) != findp({ i,j + 1 })) {
                board[findp({ i,j + 1 }).first][findp({ i,j + 1 }).second] += board[findp({ i,j }).first][findp({ i,j }).second];
                parent[findp({ i,j }).first][findp({ i,j }).second] = findp({ i ,j + 1 });
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (findp({ i,j }) != make_pair(i, j)) continue;
            if (board[i][j] != 0) {
                cout << "No";
                return;
            }
        }
    }

    cout << "Yes";




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