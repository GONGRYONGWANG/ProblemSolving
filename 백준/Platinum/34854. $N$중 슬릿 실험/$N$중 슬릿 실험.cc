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


ll arr[102][2];

ld DP[102][2];

ld dist(ll a, ll b, bool x, bool y) {
    ll p = arr[a][x];
    ll q = arr[b][y];
    for (ll i = b + 1; i < a; i++) {
        ld m = ld(q * (a - i) + p * (i - b)) / (a - b);
        if (m<arr[i][0] || m>arr[i][1]) return INF;
    }
    return sqrt((a - b) * (a - b) + (p - q) * (p - q));
}

void solve(int tc) {

    ll M, N;
    cin >> M >> N;


    for (int i = 1; i <= N; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    DP[0][0] = DP[0][1] = 0;

    for (int i = 1; i <= N + 1; i++) {
        DP[i][0] = DP[i][1] = INF;
        for (int j = 0; j < i; j++) {
            DP[i][0] = min(DP[i][0], DP[j][0] + dist(i, j, 0, 0));
            DP[i][0] = min(DP[i][0], DP[j][1] + dist(i, j, 0, 1));
            DP[i][1] = min(DP[i][1], DP[j][0] + dist(i, j, 1, 0));
            DP[i][1] = min(DP[i][1], DP[j][1] + dist(i, j, 1, 1));
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << DP[N + 1][0];



    // cout << "Case #" << tc << ": " << ret << endl;
}


int main() {
    // fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}