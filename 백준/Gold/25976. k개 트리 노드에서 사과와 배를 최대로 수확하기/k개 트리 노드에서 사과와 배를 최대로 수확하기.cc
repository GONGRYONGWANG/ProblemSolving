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

int DP[17][18][18];

int parent[17];
int ind[17];

void solve(int tc) {

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        for (int a = 0; a <= K; a++) {
            for (int b = 0; b <= K; b++) {
                DP[i][a][b] = inf;
            }
        }
    }


    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        parent[v] = u;
        ind[u] += 1;
    }

    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        if (x == 1) DP[i][1][0] = 1;
        else if (x == 2) DP[i][0][1] = 1;
        else DP[i][0][0] = 1;
    }

    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (ind[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == 0) continue;
        int p = parent[x];
        for (int i = K; i >= 0; i--) {
            for (int j = K; j >= 0; j--) {
                for (int a = 0; a + i <= K; a++) {
                    for (int b = 0; b + j <= K; b++) {
                        DP[p][i + a][j + b] = min(DP[p][i + a][j + b], DP[p][i][j] + DP[x][a][b]);
                    }
                }
            }
        }
        ind[p] -= 1;
        if (ind[p] == 0) q.push(p);
    }

    pii ret = { 0,0 };

    for (int i = 0; i <= K; i++) {
        for (int j = 0; j <= K; j++) {
            if (DP[0][i][j] > K) continue;
            if (i * j > ret.first * ret.second) {
                ret = { i,j };
            }
            else if (i * j == ret.first * ret.second) {
                if (i > ret.first) {
                    ret = { i,j };
                }
                else if (i == ret.first && j > ret.second) {
                    ret = { i,j };
                }
            }
        }
    }

    cout << ret.first << " " << ret.second;





    // cout << "Case #" << tc << ": " << ret<< endl;
}

int main() {
    //fin.open("input.txt"); fout.open("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }

    return 0;
}