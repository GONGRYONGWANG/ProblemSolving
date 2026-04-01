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

bool visited[100][100][4];
char board[100][100];

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    queue<tuple<int, int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'W') {
                for (int dir = 0; dir < 4; dir++) {
                    q.push({ i,j,dir });
                    visited[i][j][dir] = true;
                }
            }
        }
    }

    while (!q.empty()) {
        auto [x, y, d] = q.front();
        q.pop();

        if (board[x][y] == '.') {
            for (int dir = 0; dir < 4; dir++) {
                if (!visited[x][y][dir]) {
                    q.push({ x,y,dir });
                    visited[x][y][dir] = true;
                }
            }
        }

        int nx = x + dx[d]; int ny = y + dy[d];
        if (visited[nx][ny][d]) continue;

        if (board[nx][ny] == '#') {
            for (int dir = 0; dir < 4; dir++) {
                if (!visited[x][y][dir]) {
                    q.push({ x,y,dir });
                    visited[x][y][dir] = true;
                }
            }
        }
        else {
            q.push({ nx,ny,d });
            visited[nx][ny][d] = true;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] != '.') {
                cout << board[i][j];
                continue;
            }
            bool b = false;
            for (int dir = 0; dir < 4; dir++) {
                b |= visited[i][j][dir];
            }
            if (b) cout << '.';
            else cout << 'P';
        }
        cout << endl;
    }




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