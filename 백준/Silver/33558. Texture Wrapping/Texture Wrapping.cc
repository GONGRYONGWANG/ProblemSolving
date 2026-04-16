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

//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


char board[400][400];

void solve(int tc) {

    int N, M;
    cin >> N >> M;
    int U, V;
    cin >> U >> V;
    for (int i = 0; i < U; i++) {
        for (int j = 0; j < V; j++) {
            cin >> board[i][j];
        }
    }


    string s;
    cin >> s;
    if (s == "clamp-to-edge") {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int x = min(i, U - 1); int y = min(j, V - 1);
                cout << board[x][y];
            }
            cout << endl;
        }
        return;
    }

    if (s == "mirrored-repeat") {
        for (int i = U; i < 2 * U; i++) {
            for (int j = 0; j < V; j++) {
                board[i][j] = board[2 * U - 1 - i][j];
            }
        }
        for (int i = 0; i < U; i++) {
            for (int j = V; j < 2 * V; j++) {
                board[i][j] = board[i][2 * V - 1 - j];
            }
        }
        for (int i = U; i < 2 * U; i++) {
            for (int j = V; j < 2 * V; j++) {
                board[i][j] = board[2 * U - 1 - i][2 * V - 1 - j];
            }
        }
        U *= 2; V *= 2;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << board[i % U][j % V];
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