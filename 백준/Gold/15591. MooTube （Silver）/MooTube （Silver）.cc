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
///////////////////////////////////////////////////////////////


int adj[5001][5001];

int parent[5001];
int findp(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}

void solve(int tc) {

    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> edges(N - 1);
    for (int i = 0; i < N - 1; i++) {
        int p, q, r;
        cin >> p >> q >> r;
        edges[i] = { r,p,q };
    }
    sort(edges.rbegin(), edges.rend());

    for (int i = 1; i <= N; i++) parent[i] = i;

    for (int i = 0; i < N - 1; i++) {
        int u = edges[i][1]; int v = edges[i][2];
        int w = edges[i][0];
        u = findp(u); v = findp(v);
        vector<int> U;
        vector<int> V;
        for (int j = 1; j <= N; j++) {
            if (findp(j) == u) U.push_back(j);
            else if (findp(j) == v) V.push_back(j);
        }
        for (int x : U) {
            for (int y : V) {
                adj[x][y] = adj[y][x] = w;
            }
        }
        parent[v] = u;
    }

    while (Q--) {
        int k, v;
        cin >> k >> v;
        int ret = 0;
        for (int i = 1; i <= N; i++) {
            if (adj[v][i] >= k) ret += 1;
        }
        cout << ret << endl;
    }




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