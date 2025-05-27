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

int N, M;

int get(int bit, vector<vector<bool>> board) {
    int ret = 0;
    for (int j = 0; j < M; j++) {
        if ((bit & (1 << (M - 1 - j))) == 0) continue;
        ret += 1;
        board[0][j] = !board[0][j];
        for (int dir = 0; dir < 4; dir++) {
            int nx = 0 + dx[dir]; int ny = j + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            board[nx][ny] = !board[nx][ny];
        }
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ret += board[i - 1][j];
            if (!board[i - 1][j]) continue;
            board[i][j] = !board[i][j];
            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir]; int ny = j + dy[dir];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                board[nx][ny] = !board[nx][ny];
            }
        }
    }

    for (int j = 0; j < M; j++) {
        if (board[N - 1][j]) return inf;
    }

    return ret;
}

void printmn(int bit,vector<vector<bool>> board) {
    for (int j = 0; j < M; j++) {
        if ((bit & (1 << (M - 1 - j))) == 0) {
            cout << 0 << " ";
            continue;
        }
        cout << 1 << " ";
        board[0][j] = !board[0][j];
        for (int dir = 0; dir < 4; dir++) {
            int nx = 0 + dx[dir]; int ny = j + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            board[nx][ny] = !board[nx][ny];
        }
    }
    cout << endl;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << board[i - 1][j] << " ";
            if (!board[i - 1][j]) continue;
            board[i][j] = !board[i][j];
            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir]; int ny = j + dy[dir];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                board[nx][ny] = !board[nx][ny];
            }
        }
        cout << endl;
    }

}

void solve(int tc) {
    
    cin >> N >> M;
    vector<vector<bool>> board(N, vector<bool>(M));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            board[i][j] = x;
        }
    }


    int mn = inf;
    int ret = -1;
    for (int bit = 0; bit < (1 << M); bit++) {
        int val = get(bit, board);
        if (val < mn) {
            mn = val;
            ret = bit;
        }
    }

    if (ret == -1) {
        cout << "IMPOSSIBLE";
        return;
    }


    printmn(ret, board);

    






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