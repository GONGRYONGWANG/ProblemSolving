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
#include<optional>
#include<bit>
using namespace std;
using ll = long long;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef complex<double> cpx;
typedef long double ld;
#define pq priority_queue
#define endl "\n"
#define INF ll(1e18)
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
//int dx8[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy8[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

ll board[18][18];

int popcount(unsigned int x) {
    int cnt = 0;
    while (x) {
        cnt += x & 1;
        x >>= 1;
    }
    return cnt;
}

void solve(int tc) {

    int N, M, R, S;
    cin >> N >> M >> R >> S;

    ll mx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            mx = max(mx, board[i][j]);
        }
    }

    ll ret = INF;
    for (unsigned int bit = 0; bit < (1 << N); bit++) {
        if (popcount(bit) != R || (bit & (1 << (N - 1)))) continue;
        bit |= (1 << (N - 1));
        ll l = mx; ll r = INF;
        while (l < r) {
            ll m = (l + r) / 2;
            vector<ll> psum(N, 0);
            ll cnt = 0;
            for (int j = 0; j < M; j++) {
                vector<ll> nx(N, 0);
                bool flag = false;
                for (int i = 0; i < N; i++) {
                    nx[i] += board[i][j];
                    if ((bit & (1 << i))) {
                        if (nx[i] > m) cnt = INF;
                        psum[i] += nx[i];
                        flag |= (psum[i] > m);
                    }
                    else {
                        nx[i + 1] += nx[i];
                        nx[i] = 0;
                    }
                }
                if (cnt == INF) break;
                if (flag) {
                    cnt += 1;
                    for (int i = 0; i < N; i++) psum[i] = 0;
                    j -= 1;
                }
            }

            if (cnt <= S) r = m;
            else l = m + 1;
        }
        ret = min(ret, l);
        bit -= (1 << (N - 1));
    }

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