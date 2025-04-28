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


pll adj[100][100];

void solve(int tc) {

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            adj[i][j] = { inf,0 };
        }
        adj[i][i] = { 0,0 };
    }

    vector<vector<ll>> edges(M);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = adj[v][u] = { w,1 };
        edges[i] = { u,v,w };
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (adj[i][k].first + adj[k][j].first < adj[i][j].first) {
                    adj[i][j] = { adj[i][k].first + adj[k][j].first , 0 };
                }
                if (adj[i][k].first + adj[k][j].first == adj[i][j].first) {
                    adj[i][j].second += adj[i][k].second * adj[k][j].second;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        adj[i][i] = { 0,1 };
    }
    
    for (int k = 0; k < M; k++) {
        int u, v, w;
        u = edges[k][0]; v = edges[k][1]; w = edges[k][2];
        if (adj[u][v].first != w || adj[u][v].second != 1) {
            cout << 0 << " "; 
            continue;
        }

        int ret = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (adj[i][u].first + w + adj[v][j].first == adj[i][j].first && adj[i][j].second == adj[i][u].second * adj[v][j].second) ret += 1;
            }
        }

        cout << ret << " ";

    }

    cout << endl;

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