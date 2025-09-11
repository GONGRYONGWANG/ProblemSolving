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

pii E[123457];

short parent[50001][701];
int findp(int k, int x) {
    if (parent[k][x] == x) return x;
    return parent[k][x] = findp(k, parent[k][x]);
}

void mer(int k, int u, int v) {
    u = findp(k, u); v = findp(k, v);
    parent[k][u] = v;
}

void solve(int tc) {

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> E[i].first >> E[i].second;
    }

    int Q; cin >> Q;

    vector<pii> L(Q);
    vector<pii> R(Q);

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        L[i] = { l,i };
        R[i] = { r,i };
        for (int j = 1; j <= N; j++) parent[i][j] = j;
    }

    sort(L.begin(), L.end());
    sort(R.rbegin(), R.rend());

    for (int j = 1; j <= N; j++) parent[Q][j] = j;
    int pos = 1;
    for (auto& [l, i] : L) {
        while (pos < l) {
            auto& [u, v] = E[pos];
            mer(Q, u, v);
            pos += 1;
        }
        for (int j = 1; j <= N; j++) mer(i, j, findp(Q, j));
    }


    for (int j = 1; j <= N; j++) parent[Q][j] = j;
    pos = M;
    for (auto& [r, i] : R) {
        while (pos > r) {
            auto& [u, v] = E[pos];
            mer(Q, u, v);
            pos -= 1;
        }
        for (int j = 1; j <= N; j++) mer(i, j, findp(Q, j));
    }


    for (int i = 0; i < Q; i++) {
        int ret = 0;
        for (int j = 1; j <= N; j++) ret += (findp(i, j) == j);
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