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
//int dx8[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy8[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////


ll DP[64][64][11];

void solve(int tc) {

    if (tc == 1) {
        for (int m = 2; m <= 10; m++) {
            for (int i = 0; i < 64; i++) {
                DP[i][0][m] = 1;
                for (int j = 1; j <= i; j++) {
                    DP[i][j][m] = DP[i - 1][j - 1][m] * (m - 1) + DP[i - 1][j][m];
                }
            }
        }
    }

    ll a, b, m, n;
    cin >> a >> b >> m >> n;

    if (n > 63) {
        cout << 0 << endl;
        return;
    }

    a -= 1;

    ll ret = 0;

    vector<ll> A, B;

    while (a || b) {
        A.push_back(a % m);
        a /= m;
        B.push_back(b % m);
        b /= m;
    }
    
    int an = n; int bn = n;
    for (int i = A.size() - 1; i >= 0; i--) {

        if (B[i] != 0 && bn >= 1) ret += DP[i][bn - 1][m] * (B[i] - 1);
        if (B[i] != 0 && bn >= 0) ret += DP[i][bn][m];

        if (A[i] != 0 && an >= 1) ret -= DP[i][an - 1][m] * (A[i] - 1);
        if (A[i] != 0 && an >= 0) ret -= DP[i][an][m];

        bn -= (B[i] != 0); an -= (A[i] != 0);
    }

    cout << ret + (bn == 0) - (an == 0) << endl;


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