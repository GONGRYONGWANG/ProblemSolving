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



ll DP[5002][5002][2];


void solve(int tc) {

    ll N, M;
    cin >> N >> M;
    vector<pll> arr(N + 2);
    arr[0] = { -INF,0 };
    arr[1] = { 0,0 };
    for (int i = 2; i < N + 2; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end());

    for (int i = 1; i < N + 2; i++) {
        arr[i].second += arr[i - 1].second;
    }

    int s = 0;
    while(arr[s].first != 0) s++;


    ll ret = M;
    DP[s][s][0] = DP[s][s][1] = 0;
    for (int l = s; l >= 1; l--) {
        for (int r = s; r < N + 2; r++) {
            if (l == s && r == s) continue;
            DP[l][r][0] = DP[l][r][1] = INF;

            if (l != s && DP[l + 1][r][0] + arr[l + 1].first - arr[l].first < M + arr[r].second - arr[l].second) {
                DP[l][r][0] = min(DP[l][r][0], DP[l + 1][r][0] + arr[l + 1].first - arr[l].first);
            }
            if (l != s && DP[l + 1][r][1] + arr[r].first - arr[l].first < M + arr[r].second - arr[l].second) {
                DP[l][r][0] = min(DP[l][r][0], DP[l + 1][r][1] + arr[r].first - arr[l].first);
            }

            if (r != s && DP[l][r - 1][0] + arr[r].first - arr[l].first < M + arr[r - 1].second - arr[l - 1].second) {
                DP[l][r][1] = min(DP[l][r][1], DP[l][r - 1][0] + arr[r].first - arr[l].first);
            }
            if (r != s && DP[l][r - 1][1] + arr[r].first - arr[r - 1].first < M + arr[r - 1].second - arr[l - 1].second) {
                DP[l][r][1] = min(DP[l][r][1], DP[l][r - 1][1] + arr[r].first - arr[r - 1].first);
            }

            if (DP[l][r][0] != INF || DP[l][r][1] != INF) ret = max(ret, M + arr[r].second - arr[l - 1].second);
        }
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