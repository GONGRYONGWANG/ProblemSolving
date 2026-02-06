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

//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


int DP[100][100][201][2];
int D[100][100];
int R[100][100];

void solve(int tc) {

    int M, N, L, G;
    cin >> M >> N >> L >> G;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N - 1; j++) {
            cin >> R[i][j];
        }
    }

    for (int i = 0; i < M - 1; i++) {
        for (int j = 0; j < N; j++) {
            cin >> D[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            for (int cnt = 0; cnt < M + N; cnt++) {
                DP[i][j][cnt][0] = DP[i][j][cnt][1] = inf;
            }
        }
    }

    DP[0][0][0][0] = 0;
    DP[0][0][0][1] = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            for (int cnt = 0; cnt < M + N; cnt++) {
                if (cnt != M + N - 1) {
                    DP[i][j][cnt + 1][1] = min(DP[i][j][cnt + 1][1], DP[i][j][cnt][0]);
                    DP[i][j][cnt + 1][0] = min(DP[i][j][cnt + 1][0], DP[i][j][cnt][1]);
                }
                if (i != M - 1) {
                    DP[i + 1][j][cnt][0] = min(DP[i + 1][j][cnt][0], DP[i][j][cnt][0] + D[i][j]);
                }
                if (j != N - 1) {
                    DP[i][j + 1][cnt][1] = min(DP[i][j + 1][cnt][1], DP[i][j][cnt][1] + R[i][j]);
                }
            }
        }
    }

    for (int cnt = 0; cnt < M + N; cnt++) {
        if (DP[M - 1][N - 1][cnt][0] <= G || DP[M - 1][N - 1][cnt][1] <= G) {
            cout << L * (M - 1 + N - 1) + cnt << endl;
            return;
        }
    }


    cout << -1 << endl;


    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    rng_init();
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}