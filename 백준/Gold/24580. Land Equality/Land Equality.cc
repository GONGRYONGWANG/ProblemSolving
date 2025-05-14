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

//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

int board[64][64];
int cnt[3];

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            cnt[board[i][j]] += 1;
        }
    }

    if (cnt[0] >= 2) {
        cout << 0;
        return;
    }

    if (cnt[0] == 1) {
        if (cnt[1] == 0) {
            cout << 2;
            return;
        }
        if (N == 1) {
            if (board[0][0] == 0) {
                cout << board[0][M - 1];
            }
            else if (board[0][M - 1] == 0) {
                cout << board[0][0];
            }
            else cout << min(board[0][0], board[0][M - 1]);
            return;
        }
        if (M == 1) {
            if (board[0][0] == 0) {
                cout << board[N - 1][0];
            }
            else if (board[N - 1][0] == 0) {
                cout << board[0][0];
            }
            else cout << min(board[0][0], board[N - 1][0]);
            return;
        }
        cout << 1;
        return;
    }

    if (cnt[2] % 2 == 0) {
        cout << 0;
        return;
    }

    cout << (1ll << (cnt[2] / 2));



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