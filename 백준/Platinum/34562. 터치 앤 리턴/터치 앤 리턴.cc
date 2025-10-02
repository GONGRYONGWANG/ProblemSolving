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
const long double pi = 3.14159265358979323846;
const string debug = "debug: ";
#define all(x) (x).begin(), (x).end()
#include<fstream>
ifstream fin; ofstream fout;


//int dx[4] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//int dx[8] = { -1,-1,-1,0,1,1,1,0 };
//int dy[8] = { -1,0,1,1,1,0,-1,-1 };

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////

int popcount(uint n) { // https://blog.naver.com/jinhan814/222540111549
    n = (n >> 1 & 0x55555555) + (n & 0x55555555);
    n = (n >> 2 & 0x33333333) + (n & 0x33333333);
    n = (n >> 4 & 0x0F0F0F0F) + (n & 0x0F0F0F0F);
    n = (n >> 8 & 0x00FF00FF) + (n & 0x00FF00FF);
    n = (n >> 16 & 0x0000FFFF) + (n & 0x0000FFFF);
    return n;
}

int adj[20][20];
int DP[20][(1 << 20)];


void solve(int tc) {

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            adj[i][j] = K+1;
        }
        adj[i][i] = 0;
    }

    while (M--) {
        int u, v;
        cin >> u >> v;
        u -= 1; v -= 1;
        int c; cin >> c;
        adj[v][u] = adj[u][v] = min(adj[u][v], c);
    }


    for (int k = 1; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (1 << N); j++) {
            DP[i][j] = K+1;
        }
    }

    DP[0][0] = 0;


    for (int bit = 0; bit < (1 << N); bit+=2) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                DP[j][bit | (1 << j)] = min(DP[j][bit | (1 << j)], DP[i][bit] + adj[i][j]);
            }
        }
    }


    vector<int> v(N, K + 1);
    for (int bit = 1; bit < (1 << N); bit+=2) {
        v[popcount(bit) - 1] = min(v[popcount(bit) - 1], DP[0][bit]);
    }


    vector<int> ret(K + 1, 0);

    for (int i = 1; i < N; i++) {
        int x = v[i];
        for (ll j = 0; j + x <= K; j++) {
            ret[j + x] = max(ret[j + x], ret[j] + i * i);
        }
    }

    cout << ret[K];


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