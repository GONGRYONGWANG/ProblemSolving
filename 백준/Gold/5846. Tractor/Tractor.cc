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



int board[501][501];
int sz[250000];
int parent[250000];
int findp(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}

void solve(int tc) {

    int N;
    cin >> N;
    
    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            parent[i * N + j] = i * N + j;
            cin >> board[i][j];
            sz[i * N + j] = 1;
            if (i != 0) {
                edges.push_back({ abs(board[i][j] - board[i - 1][j]), i * N + j,i * N + j - N });
            }
            if (j != 0) {
                edges.push_back({ abs(board[i][j] - board[i][j - 1]), i * N + j,i * N + j - 1 });
            }
        }
    }

    sort(edges.begin(), edges.end());

    if (N == 1) {
        cout << 0;
        return;
    }

    for (auto& [w, u, v] : edges) {
        u = findp(u); v = findp(v);
        if (u == v) continue;
        sz[u] += sz[v];
        parent[v] = u;
        if (sz[u] >= (N * N + 1) / 2) {
            cout << w;
            return;
        }
    }


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