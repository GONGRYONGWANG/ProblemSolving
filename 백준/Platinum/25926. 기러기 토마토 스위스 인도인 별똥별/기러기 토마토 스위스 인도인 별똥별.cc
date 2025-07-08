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

bool A[2001][2001];
int board[1001][1001];
int lazy[1001][1001];

int mer(int x, int y) {
    if (x == y) return 0;
    if (x == 0) return y;
    if (y == 0) return x;
    return 6 - x - y;
}

void solve(int tc) {

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char x; cin >> x;
            A[i][j] = (x == '1');
        }
    }

    for (int i = 1; i <= N / 2; i++) {
        for (int j = 1; j <= M / 2; j++) {
            bool a = A[i][j], b = A[i][M + 1 - j];
            bool c = A[N + 1 - i][j], d = A[N + 1 - i][M + 1 - j];
            if (a == b && a == c && a == d) board[i][j] = 0;    
            else if (a == b && a != c && a != d) board[i][j] = 1;
            else if (a == c && a != b && a != d) board[i][j] = 2;
            else if (a == d && a != b && a != c) board[i][j] = 3;
            else {
                cout << -1;
                return;
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= N / 2; i++) {
        int psum = 0;
        for (int j = 1; j <= M / 2; j++) {
            psum = mer(psum, mer(lazy[i][j - 1], lazy[max(i - K, 0)][j - 1]));
            psum = mer(psum, mer(lazy[i][max(j - K, 0)], lazy[max(i - K, 0)][max(j - K, 0)]));
            lazy[i][j] = mer(board[i][j], mer(psum, mer(lazy[i - 1][j], lazy[max(i - K, 0)][j])));
            if (lazy[i][j] != 0) {
                if (i + K - 1 > N / 2 || j + K - 1 > M / 2) {
                    cout << -1;
                    return;
                }
                ans += 1;
            }
            lazy[i][j] = mer(lazy[i][j], lazy[i - 1][j]);
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