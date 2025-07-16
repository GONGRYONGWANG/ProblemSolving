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
#define INF ll(2e18)
const int inf = 1000000007;
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

bool board[2000][2000];
ll hash_board[2000][2000];
ll hash_board2[2000][2000];
ll hash_board3[2000][2000];

void solve(int tc) {
    int H, W, N, M;
    cin >> H >> W >> N >> M;

    ll hash_pattern = 0;
    ll hash_pattern2 = 0;
    ll hash_pattern3 = 0;

    ll p = 1e9 + 33;
    ll p2 = 1e9 + 21;
    ll p3 = 1e9 + 9;

    for (int i = 0; i < H; i++) {
        ll hashval = 0;
        ll hashval2 = 0;
        ll hashval3 = 0;
        for (int j = 0; j < W; j++) {
            char x; cin >> x;
            hashval *= p;
            hashval += (x == 'o');

            hashval2 *= p2;
            hashval2 += (x == 'o');

            hashval3 *= p3;
            hashval3 += (x == 'o');
        }
        hash_pattern *= p2;
        hash_pattern += hashval;

        hash_pattern2 *= p3;
        hash_pattern2 += hashval2;

        hash_pattern3 *= p;
        hash_pattern3 += hashval3;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char x; cin >> x;
            board[i][j] = (x == 'o');
        }
    }

    ll powp = 1;
    ll powp2 = 1;
    ll powp3 = 1;
    for (int i = 0; i < W; i++) {
        powp = powp * p;
        powp2 = powp2 * p2;
        powp3 = powp3 * p3;
    }

    for (int i = 0; i < N; i++) {
        ll hashval = 0;
        ll hashval2 = 0;
        ll hashval3 = 0;
        for (int j = 0; j < W; j++) {
            hashval *= p;
            hashval += board[i][j];

            hashval2 *= p2;
            hashval2 += board[i][j];

            hashval3 *= p3;
            hashval3 += board[i][j];
        }
        hash_board[i][0] = hashval;
        hash_board2[i][0] = hashval2;
        hash_board3[i][0] = hashval3;

        for (int j = W; j < M; j++) {
            hashval *= p;
            hashval -= powp * board[i][j - W];
            hashval += board[i][j];
            hash_board[i][j - W + 1] = hashval;

            hashval2 *= p2;
            hashval2 -= powp2 * board[i][j - W];
            hashval2 += board[i][j];
            hash_board2[i][j - W + 1] = hashval2;

            hashval3 *= p3;
            hashval3 -= powp3 * board[i][j - W];
            hashval3 += board[i][j];
            hash_board3[i][j - W + 1] = hashval3;
        }
    }

    powp = 1; powp2 = 1; powp3 = 1;
    for (int i = 0; i < H; i++) {
        powp = powp * p;
        powp2 = powp2 * p2;
        powp3 = powp3 * p3;
    }

    int ans = 0;

    for (int j = 0; j <= M - W; j++) {
        ll hashval = 0;
        ll hashval2 = 0;
        ll hashval3 = 0;
        for (int i = 0; i < H; i++) {
            hashval *= p2;
            hashval += hash_board[i][j];

            hashval2 *= p3;
            hashval2 += hash_board2[i][j];

            hashval3 *= p;
            hashval3 += hash_board3[i][j];
        }
        ans += (hashval == hash_pattern && hashval2 == hash_pattern2 && hashval3 == hash_pattern3);
        for (int i = H; i < N; i++) {
            hashval *= p2;
            hashval -= powp2 * hash_board[i - H][j];
            hashval += hash_board[i][j];

            hashval2 *= p3;
            hashval2 -= powp3 * hash_board2[i - H][j];
            hashval2 += hash_board2[i][j];

            hashval3 *= p;
            hashval3 -= powp * hash_board3[i - H][j];
            hashval3 += hash_board3[i][j];

            ans += (hashval == hash_pattern && hashval2 == hash_pattern2 && hashval3 == hash_pattern3);
        }
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