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

ll board[2001][2000];
ll DP[2001][2000];

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    
    if (M == 1) {
        ll ret = board[0][0];
        if (ret > 0) cout << "djangg7 " << ret;
        else cout << "ibasic " << ret;
        return;
    }


    ll mx1 = 0, mx2 = 0;
    int mxidx1 = 0, mxidx2 = 1;
    for (int i = N - 1; i >= 0; i--) {

        for (int j = 0; j < M; j++) {
            DP[i][j] = board[i][j];
            if (j != mxidx1) {
                DP[i][j] -= max(mx1, DP[i + 1][j] - board[i + 1][j]);
            }
            else {
                DP[i][j] -= max(mx2, DP[i + 1][j] - board[i + 1][j]);
            }
        }

        mx1 = -INF; mx2 = -INF;
        mxidx1 = -1, mxidx2 = -1;
        for (int j = 0; j < M; j++) {
            if (DP[i][j] > mx1) {
                mx2 = mx1; mxidx2 = mxidx1;
                mx1 = DP[i][j]; mxidx1 = j;
            }
            else if (DP[i][j] > mx2) {
                mx2 = DP[i][j]; mxidx2 = j;
            }
        }
        
    }
    
    if (mx1 > 0) cout << "djangg7 " << mx1;
    else cout << "ibasic " << -mx1;



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