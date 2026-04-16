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

//int dx[4] = { -1,0,1,0 }; 
//int dy[4] = { 0,-1,0,1 }; 
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


int dx[4] = { -1,0,0,-1 };
int dy[4] = { -1,-1,0,0 };

int cnt[8][8];
int board[9][9];



void solve(int tc) {

    int total = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char x;
            cin >> x;
            board[i][j] = (x == 'O');
            total += board[i][j];
        }
    }

    int x = 1, y = 1;

    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) {
            for (int dir = 0; dir < 4; dir++) cnt[i][j] += board[i + dx[dir]][j + dy[dir]];
            if (cnt[i][j] > cnt[x][y]) x = i, y = j;
        }
    }

    cout << x << " " << y << endl;
    int r = cnt[x][y];
    if (r == 0) {
        cout << 0;
        return;
    }

    ld ans = 1;
    for (int i = 0; i < 4; i++) {
        ans *= total - r - i;
        ans /= total - i;
    }

    cout << fixed;
    cout.precision(10);
    cout << 1 - ans;
    






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