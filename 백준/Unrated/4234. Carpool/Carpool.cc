// template: https://github.com/GONGRYONGWANG/ProblemSolving/blob/main/template.txt
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
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
#define INF ll(9e18)
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
int popcount(uint n) { // https://blog.naver.com/jinhan814/222540111549
    n = (n >> 1 & 0x55555555) + (n & 0x55555555);
    n = (n >> 2 & 0x33333333) + (n & 0x33333333);
    n = (n >> 4 & 0x0F0F0F0F) + (n & 0x0F0F0F0F);
    n = (n >> 8 & 0x00FF00FF) + (n & 0x00FF00FF);
    n = (n >> 16 & 0x0000FFFF) + (n & 0x0000FFFF);
    return n;
}
///////////////////////////////////////////////////////////////


ll d[17][17];

ll DP[(1 << 15)];

void solve(int tc) {

    ll N, M;
    cin >> N >> M;

    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j <= N + 1; j++) {
            d[i][j] = inf;
        }
        d[i][i] = 0;
    }

    while (M--) {
        ll u, v, w;
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
        d[v][u] = d[u][v];
    }

    for (int k = 0; k <= N + 1; k++) {
        for (int i = 0; i <= N + 1; i++) {
            for (int j = 0; j <= N + 1; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    for (int i = 0; i < (1 << N); i++) {
        DP[i] = INF;
    }

    vector<int> arr;
    for (int bit = 1; bit < (1 << N); bit++) {
        if (popcount(bit) > 5) continue;
        vector<int> v;
        for (int i = 0; i < N; i++) {
            if (bit & (1 << i)) v.push_back(i + 1);
        }
        sort(v.begin(), v.end());

        ll ret = INF;
        do {
            ll dist = 5 * popcount(bit);
            int prv = 0;
            for (int x : v) {
                dist += d[prv][x];
                prv = x;
            }
            dist += d[prv][N + 1];
            ret = min(ret, dist);
        } while (next_permutation(v.begin(), v.end()));
        arr.push_back(bit);
        DP[bit] = ret;
    }

    if (N <= 5) {
        cout << DP[(1 << N) - 1];
        return;

    }

    ll ans = INF;

    if (N <= 10) {
        for (int bit : arr) {
            if (N - popcount(bit) > 5) continue;
            ans = min(ans, max(DP[bit], DP[(1 << N) - 1 - bit]));
        }
        cout << ans;
        return;
    }


    for (int bit1 : arr) {
        for (int bit2 : arr) {
            if (bit1 & bit2) continue;
            if (popcount(bit1 | bit2) <= 5) continue;
            if (N - popcount(bit1 | bit2) <= 5) {
                ans = min(ans, max(max(DP[bit1], DP[bit2]), DP[(1 << N) - 1 - (bit1 | bit2)]));
            }
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