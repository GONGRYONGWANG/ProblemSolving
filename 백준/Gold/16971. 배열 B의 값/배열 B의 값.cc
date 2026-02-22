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

int board[1000][1000];

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    ll total = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            int d = (1 + (i != 0 && i != N - 1)) * (1 + (j != 0 && j != M - 1));
            total += d * board[i][j];
        }
    }

    ll rsum_mx = -inf;
    ll rsum_mn = inf;

    for (int i = 0; i < N; i++) {
        ll sum = 0;
        for (int j = 0; j < M; j++) {
            sum += (1 + (j != 0 && j != M - 1)) * board[i][j];
        }
        if (i != 0 && i != N - 1) rsum_mn = min(rsum_mn, sum);
        else rsum_mx = max(rsum_mx, sum);
    }

    ll csum_mx = -inf;
    ll csum_mn = inf;

    ll ret = total;
    ret = max(ret, total - rsum_mn + rsum_mx);

    for (int j = 0; j < M; j++) {
        ll sum = 0;
        for (int i = 0; i < N; i++) {
            sum += (1 + (i != 0 && i != N - 1)) * board[i][j];
        }
        if (j != 0 && j != M - 1) csum_mn = min(csum_mn, sum);
        else csum_mx = max(csum_mx, sum);
    }

    ret = max(ret, total - csum_mn + csum_mx);

    cout << ret;

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