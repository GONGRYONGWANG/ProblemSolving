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
#define INF ll(4e18)
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

int parent[100001];
int sz[100001];
int findp(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x]);
}

int con[1000001][30];


void solve(int tc) {

    int N, P, Q;
    cin >> N >> P >> Q;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        sz[i] = 1;
        con[i][i % P] = i;
    }

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            u = findp(u); v = findp(v);
            if (con[u][v % P] == v) continue;

            vector<int> nxcon(P, 0);
            for (int i = 0; i < P; i++) {
                if (!con[u][i] && !con[v][i]) continue;

                if (con[u][i]) nxcon[i] = con[u][i];
                else nxcon[i] = con[v][i];

                if (con[u][i] && con[v][i]) {
                    parent[con[v][i]] = con[u][i];
                    sz[con[u][i]] += sz[con[v][i]];
                }

            }

            for (int i = 0; i < P; i++) {
                for (int j = 0; j < P; j++) {
                    if (!nxcon[i]) continue;
                    con[nxcon[i]][j] = nxcon[j];
                }
            }


        }
        else if (t == 2) {
            int x, k;
            cin >> x >> k;
            x = findp(x);
            if (!con[x][k]) continue;

            for (int i = 0; i < P; i++) {
                if (con[x][i] && i % P != k) x = con[x][i];
            }

            if (x % P == k) continue;


            for (int j = 0; j < P; j++) {
                if (j == k) continue;
                con[con[x][k]][j] = 0;
            }

            con[x][k] = 0;
            for (int i = 0; i < P; i++) {
                if (!con[x][i]) continue;
                con[con[x][i]][k] = 0;
            }
        }
        else {
            int x;
            cin >> x;
            x = findp(x);
            int ret = 0;
            for (int i = 0; i < P; i++) {
                if (con[x][i]) ret += sz[con[x][i]];
            }
            cout << ret << endl;
        }
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